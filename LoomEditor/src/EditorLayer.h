#pragma once

#include <Loom/Core/Layer.h>

class EditorLayer final : public Loom::Layer
{
public:
    EditorLayer();

    void OnImGuiRender() override;
};
