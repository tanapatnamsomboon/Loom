#pragma once

#include "Loom/Core/Base.h"
#include <string>
#include <functional>
#include <utility>

namespace Loom
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(std::string title = "Loom Engine",
                    const unsigned int width = 1600,
                    const unsigned int height = 900)
            : Title(std::move(title)), Width(width), Height(height)
        {
        }
    };

    class Event;

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        [[nodiscard]] virtual void* GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProps& props = WindowProps());
    };
} // namespace Loom
