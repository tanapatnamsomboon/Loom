#pragma once

#include <memory>
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
                    const unsigned int width = 1280,
                    const unsigned int height = 720)
            : Title(std::move(title)), Width(width), Height(height)
        {
        }
    };

    class Event;

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(const Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
    };
} // namespace Loom
