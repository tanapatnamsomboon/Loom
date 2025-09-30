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
    void OnUpdate() override;
    void OnImGuiRender() override;

private:
    void DockspaceUI();

private:
    Loom::Ref<Loom::Framebuffer> m_Framebuffer;
    Loom::Ref<Loom::Scene> m_Scene;

    SceneHierarchyPanel m_SceneHierarchyPanel;

    Loom::Ref<Loom::VertexArray> m_VertexArray;
    Loom::Ref<Loom::Shader> m_Shader;
};
