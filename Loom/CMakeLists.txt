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
        GIT_TAG        v2.0.8
        GIT_PROGRESS   TRUE
        SOURCE_SUBDIR  cmake
)
FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_46 STATIC REPRODUCIBLE LOADER API gl:core=4.6)

target_link_libraries(Loom
        PUBLIC
        glfw
        spdlog::spdlog
        glad_gl_core_46
)

target_compile_definitions(Loom PUBLIC LOOM_PLATFORM_GLFW)
