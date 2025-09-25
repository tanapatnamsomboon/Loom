#pragma once

#include "Loom/Core/Window.h"
#include "Loom/Renderer/GraphicsContext.h"
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

        [[nodiscard]] void* GetNativeWindow() const override { return m_Window; }

    private:
        void Init(const WindowProps& props);
        void Shutdown();

    private:
        GLFWwindow* m_Window = nullptr;
        std::unique_ptr<GraphicsContext> m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
} // namespace Loom
