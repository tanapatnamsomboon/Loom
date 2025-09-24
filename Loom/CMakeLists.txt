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

target_link_libraries(Loom
        PUBLIC
        glfw
        spdlog::spdlog
)

target_compile_definitions(Loom PUBLIC LOOM_PLATFORM_GLFW)
