#pragma once

#include <Loom/Core/Layer.h>
#include <Loom/Core/Application.h>

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
};
