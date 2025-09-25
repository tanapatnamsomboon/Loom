add_executable(LoomEditor
        src/EditorApp.cpp
        src/EditorLayer.h
        src/EditorLayer.cpp
)

target_link_libraries(LoomEditor PRIVATE Loom)
