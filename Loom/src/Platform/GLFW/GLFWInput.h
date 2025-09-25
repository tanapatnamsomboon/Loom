#pragma once

#include "Loom/Core/Input.h"

namespace Loom
{
    class GLFWInput final : public Input
    {
    protected:
        [[nodiscard]] bool IsKeyPressedImpl(KeyCode key) const override;
        [[nodiscard]] bool IsMouseButtonPressedImpl(MouseCode button) const override;
        [[nodiscard]] std::pair<float, float> GetMousePositionImpl() const override;
    };
} // namespace Loom
