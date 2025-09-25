#pragma once

#include "Loom/Core/Layer.h"

namespace Loom
{
    class ImGuiLayer final : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnEvent(Event& event) override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
} // namespace Loom
