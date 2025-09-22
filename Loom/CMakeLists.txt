add_library(Loom STATIC
        src/Core/Application.h
        src/Core/Application.cpp
        src/Core/Window.h
        src/Core/Window.cpp
        src/Platform/GLFW/GLFWWindow.h
        src/Platform/GLFW/GLFWWindow.cpp
)

target_include_directories(Loom PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# --- GLFW via FetchContent ---
include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

target_link_libraries(Loom PUBLIC glfw)

target_compile_definitions(Loom PUBLIC LOOM_PLATFORM_GLFW)
