#pragma once

#include <Loom/Loom.h>
#include "Panels/SceneHierarchyPanel.h"

class EditorLayer final : public Loom::Layer
{
public:
    EditorLayer();
    ~EditorLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(Loom::Timestep ts) override;
    void OnImGuiRender() override;

private:
    void DockspaceUI();

    void OnScenePlay();
    void OnSceneStop();

private:
    Loom::Ref<Loom::Framebuffer> m_Framebuffer;

    Loom::Ref<Loom::Scene> m_EditorScene;
    Loom::Ref<Loom::Scene> m_ActiveScene;

    enum class SceneState
    {
        Edit = 0, Play = 1
    };
    SceneState m_SceneState = SceneState::Edit;

    SceneHierarchyPanel m_SceneHierarchyPanel;

    Loom::EditorCamera m_EditorCamera{ 45.0f, 1.778f, 0.1f, 1000.0f };
    glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
};
