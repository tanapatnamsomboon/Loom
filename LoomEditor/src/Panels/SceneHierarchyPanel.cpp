#include "SceneHierarchyPanel.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

template<typename T, typename UIFunction>
static void DrawComponent(const std::string& name, Loom::Entity entity, UIFunction uiFunction)
{
    if (entity.HasComponent<T>())
    {
        auto& component = entity.GetComponent<T>();

        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_SpanAvailWidth;
        bool open = ImGui::TreeNodeEx((void*)typeid(T).hash_code(), flags, "%s", name.c_str());
        if (open)
        {
            uiFunction(component);
            ImGui::TreePop();
        }
    }
}

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
        char buffer[256] = {};
        strncpy(buffer, tag.c_str(), sizeof(buffer));
        if (ImGui::InputText("Tag", buffer, sizeof(buffer)))
        {
            tag = std::string(buffer);
        }

        DrawComponent<Loom::TransformComponent>("Transform", m_SelectionContext, [](auto& component)
        {
             ImGui::DragFloat3("Translation", glm::value_ptr(component.Translation), 0.1f);
             ImGui::DragFloat3("Rotation", glm::value_ptr(component.Rotation), 0.1f);
             ImGui::DragFloat3("Scale", glm::value_ptr(component.Scale), 0.1f, 0.0f, 10.0f);
        });
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
