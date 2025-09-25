#include "EditorLayer.h"
#include <imgui.h>

EditorLayer::EditorLayer()
    : Layer("EditorLayer")
{
}

void EditorLayer::OnImGuiRender()
{
    ImGui::Begin("Loom Editor");
    ImGui::Text("Welcome to Loom Editor!");
    static float value = 0.0f;
    ImGui::SliderFloat("Value", &value, 0.0f, 1.0f);
    ImGui::End();
}
