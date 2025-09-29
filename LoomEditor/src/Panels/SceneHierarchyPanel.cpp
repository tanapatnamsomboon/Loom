#include "SceneHierarchyPanel.h"
#include <imgui.h>

SceneHierarchyPanel::SceneHierarchyPanel(const Loom::Ref<Loom::Scene>& scene)
{
    SetContext(scene);
}

void SceneHierarchyPanel::SetContext(const Loom::Ref<Loom::Scene>& scene)
{
    m_Context = scene;
    m_SelectionContext = {};
}

void SceneHierarchyPanel::OnImGuiRender()
{
    ImGui::Begin("Scene Hierarchy");
    if (m_Context)
    {
        auto view = m_Context->m_Registry.view<Loom::TagComponent>();
        for (auto entityID : view)
        {
            Loom::Entity entity{ entityID, m_Context.get() };
            DrawEntityNode(entity);
        }
    }
    ImGui::End();

    ImGui::Begin("Inspector");
    if (m_SelectionContext)
    {
        auto& tag = m_SelectionContext.GetComponent<Loom::TagComponent>().Tag;
        ImGui::Text("Selected: %s", tag.c_str());
    }
    ImGui::End();
}

void SceneHierarchyPanel::DrawEntityNode(Loom::Entity entity)
{
    auto& tag = entity.GetComponent<Loom::TagComponent>().Tag;

    ImGuiTreeNodeFlags flags = ((m_SelectionContext == entity) ? ImGuiTreeNodeFlags_Selected : 0)
        | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;

    bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, "%s", tag.c_str());

    if (ImGui::IsItemClicked())
    {
        m_SelectionContext = entity;
    }

    if (opened)
        ImGui::TreePop();
}
