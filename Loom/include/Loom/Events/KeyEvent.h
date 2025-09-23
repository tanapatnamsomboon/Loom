#pragma once

#include "Event.h"
#include <sstream>

namespace Loom
{
    class KeyEvent : public Event
    {
    public:
        [[nodiscard]] int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        explicit KeyEvent(const int keycode)
            : m_KeyCode(keycode)
        {
        }

        int m_KeyCode;
    };

    class KeyPressedEvent final : public KeyEvent
    {
    public:
        explicit KeyPressedEvent(const int keycode, const bool isRepeat = false)
            : KeyEvent(keycode), m_IsRepeat(isRepeat)
        {
        }

        [[nodiscard]] int GetRepeatCount() const { return m_IsRepeat; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressed: " << m_KeyCode;
            if (m_IsRepeat)
                ss << " (repeated)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent final : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(const int keycode)
            : KeyEvent(keycode)
        {
        }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleased: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
