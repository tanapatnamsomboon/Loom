#pragma once

#include <Loom/Loom.h>

class SceneHierarchyPanel
{
public:
    SceneHierarchyPanel() = default;
    SceneHierarchyPanel(const Loom::Ref<Loom::Scene>& scene);

    void SetContext(const Loom::Ref<Loom::Scene>& scene);

    void OnImGuiRender();

    Loom::Entity GetSelectedEntity() const { return m_SelectionContext; }

private:
    void DrawEntityNode(Loom::Entity entity);

private:
    Loom::Ref<Loom::Scene> m_Context;
    Loom::Entity m_SelectionContext;
};
