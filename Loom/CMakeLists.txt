add_library(Loom STATIC
        include/Loom/Core/Assert.h
        include/Loom/Core/Base.h
        include/Loom/Core/DebugBreak.h
        include/Loom/Core/EntryPoint.h
        include/Loom/Core/Input.h
        include/Loom/Core/KeyCode.h
        include/Loom/Core/Layer.h
        include/Loom/Core/LayerStack.h
        include/Loom/Core/Log.h
        include/Loom/Core/MouseCode.h
        include/Loom/Core/PlatformDetection.h
        include/Loom/Core/Timestep.h
        include/Loom/ImGui/ImGuiLayer.h
        include/Loom/Renderer/GraphicsContext.h
        include/Loom/Renderer/RenderCommand.h
        include/Loom/Renderer/RendererAPI.h
        include/Loom/Renderer/Framebuffer.h
        include/Loom/Renderer/Shader.h
        include/Loom/Renderer/Buffer.h
        include/Loom/Renderer/VertexArray.h
        include/Loom/Renderer/Renderer.h
        include/Loom/Scene/Component.h
        include/Loom/Scene/Entity.h
        include/Loom/Scene/Scene.h
        src/Core/Application.cpp
        src/Core/Input.cpp
        src/Core/LayerStack.cpp
        src/Core/Log.cpp
        src/Core/Window.cpp
        src/ImGui/ImGuiLayer.cpp
        src/Platform/GLFW/GLFWInput.cpp
        src/Platform/GLFW/GLFWInput.h
        src/Platform/GLFW/GLFWWindow.cpp
        src/Platform/OpenGL/OpenGLBuffer.h
        src/Platform/OpenGL/OpenGLBuffer.cpp
        src/Platform/OpenGL/OpenGLContext.cpp
        src/Platform/OpenGL/OpenGLContext.h
        src/Platform/OpenGL/OpenGLRendererAPI.cpp
        src/Platform/OpenGL/OpenGLRendererAPI.h
        src/Platform/OpenGL/OpenGLFramebuffer.cpp
        src/Platform/OpenGL/OpenGLFramebuffer.h
        src/Platform/OpenGL/OpenGLShader.h
        src/Platform/OpenGL/OpenGLShader.cpp
        src/Platform/OpenGL/OpenGLVertexArray.h
        src/Platform/OpenGL/OpenGLVertexArray.cpp
        src/Renderer/RenderCommand.cpp
        src/Renderer/Renderer.cpp
        src/Renderer/RendererAPI.cpp
        src/Renderer/Framebuffer.cpp
        src/Scene/Scene.cpp
        src/Renderer/VertexArray.cpp
        src/Renderer/Shader.cpp
        src/Renderer/Buffer.cpp
        include/Loom/Renderer/Camera.h
        include/Loom/Renderer/EditorCamera.h
        src/Renderer/EditorCamera.cpp
)

target_include_directories(Loom
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- GLFW via FetchContent ---
include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.8
        GIT_PROGRESS TRUE
        SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_46 STATIC REPRODUCIBLE LOADER API gl:core=4.6)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.92.3-docking
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(entt)

target_sources(Loom
        PRIVATE
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(Loom
        PUBLIC
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
)

target_link_libraries(Loom
        PUBLIC
        glfw
        spdlog::spdlog
        glad_gl_core_46
        EnTT::EnTT
        glm::glm
)

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    target_link_libraries(Loom
            PUBLIC
            ${X11_X11_LIB}
            ${X11_Xrandr_LIB}
            ${X11_Xi_LIB}
            ${X11_Xxf86vm_LIB}
            ${X11_Xcursor_LIB}
            pthread
    )
endif ()

target_compile_definitions(Loom PUBLIC LOOM_PLATFORM_GLFW)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Loom PUBLIC LOOM_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(Loom PUBLIC LOOM_RELEASE)
endif ()
