add_executable(LoomEditor
        src/EditorApp.cpp
        src/EditorLayer.cpp
        src/EditorLayer.h
        src/Panels/SceneHierarchyPanel.cpp
        src/Panels/SceneHierarchyPanel.h
)

target_link_libraries(LoomEditor PRIVATE Loom)

add_custom_command(TARGET LoomEditor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts
        $<TARGET_FILE_DIR:LoomEditor>/assets/fonts
)
