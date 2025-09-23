#pragma once

#include "Event.h"
#include <sstream>

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

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoved: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent final : public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset)
        {
        }

        [[nodiscard]] float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] float GetYOffset() const { return m_YOffset; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolled: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_XOffset, m_YOffset;
    };
} // namespace Loom
