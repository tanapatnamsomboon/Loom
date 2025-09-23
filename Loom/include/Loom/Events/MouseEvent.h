#pragma once

#include "Event.h"

namespace Loom
{
    class MouseMovedEvent final : public Event
    {
    public:
        explicit MouseMovedEvent(const float x, const float y)
            : m_MouseX(x), m_MouseY(y)
        {
        }

        [[nodiscard]] float GetX() const { return m_MouseX; }
        [[nodiscard]] float GetY() const { return m_MouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };
}
