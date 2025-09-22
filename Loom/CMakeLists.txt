add_library(Loom STATIC
        src/Core/Application.h
        src/Core/Application.cpp
)

target_include_directories(Loom PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
