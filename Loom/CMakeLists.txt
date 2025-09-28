add_library(Loom STATIC
        src/Core/Application.cpp
        src/Core/Window.cpp
        src/Platform/GLFW/GLFWWindow.cpp
        include/Loom/Core/Layer.h
        include/Loom/Core/LayerStack.h
        src/Core/LayerStack.cpp
        include/Loom/Core/Base.h
        include/Loom/Core/EntryPoint.h
        include/Loom/Core/Log.h
        src/Core/Log.cpp
        include/Loom/Core/Input.h
        src/Core/Input.cpp
        include/Loom/Core/MouseCode.h
        include/Loom/Core/KeyCode.h
        src/Platform/GLFW/GLFWInput.cpp
        src/Platform/GLFW/GLFWInput.h
        include/Loom/Renderer/RendererAPI.h
        include/Loom/Renderer/RenderCommand.h
        include/Loom/Renderer/GraphicsContext.h
        src/Renderer/RendererAPI.cpp
        src/Platform/OpenGL/OpenGLRendererAPI.h
        src/Platform/OpenGL/OpenGLRendererAPI.cpp
        src/Renderer/RenderCommand.cpp
        src/Platform/OpenGL/OpenGLContext.h
        src/Platform/OpenGL/OpenGLContext.cpp
        include/Loom/Core/Assert.h
        include/Loom/Core/DebugBreak.h
        include/Loom/Core/PlatformDetection.h
        include/Loom/ImGui/ImGuiLayer.h
        src/ImGui/ImGuiLayer.cpp
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
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.92.3-docking
)
FetchContent_MakeAvailable(imgui)

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
