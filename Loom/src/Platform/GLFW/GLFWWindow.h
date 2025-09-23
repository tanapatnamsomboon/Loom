#pragma once

#include "Loom/Core/Window.h"
#include <GLFW/glfw3.h>

namespace Loom
{
    class GLFWWindow final : public Window
    {
    public:
        explicit GLFWWindow(const WindowProps& props);
        ~GLFWWindow() override;

        void OnUpdate() override;

        [[nodiscard]] unsigned int GetWidth() const override { return m_Data.Width; }
        [[nodiscard]] unsigned int GetHeight() const override { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

    private:
        void Init(const WindowProps& props);
        void Shutdown();

    private:
        GLFWwindow *m_Window = nullptr;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
} // namespace Loom
