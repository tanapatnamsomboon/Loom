#pragma once

#include "Loom/Core/Base.h"
#include "Loom/Core/KeyCode.h"
#include "Loom/Core/MouseCode.h"
#include <glm/glm.hpp>

namespace Loom
{
    class Input
    {
    public:
        virtual ~Input() = default;

        static void Init();

        static bool IsKeyPressed(const KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }
        static bool IsMouseButtonPressed(const MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        static glm::vec2 GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
        static float GetMouseX() { return GetMousePosition().x; }
        static float GetMouseY() { return GetMousePosition().y; }

    protected:
        [[nodiscard]] virtual bool IsKeyPressedImpl(KeyCode key) const = 0;
        [[nodiscard]] virtual bool IsMouseButtonPressedImpl(MouseCode button) const = 0;
        [[nodiscard]] virtual glm::vec2 GetMousePositionImpl() const = 0;

    private:
        static std::unique_ptr<Input> s_Instance;
    };
} // namespace Loom
