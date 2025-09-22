#pragma once
#include "Core/Window.h"
#include <GLFW/glfw3.h>

namespace Loom
{
    class GLFWWindow : public Window
    {
    public:
        GLFWWindow(const WindowProps& props);
        virtual ~GLFWWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

    private:
        void Init(const WindowProps& props);
        void Shutdown();

    private:
        GLFWwindow *m_Window = nullptr;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
        };
        WindowData m_Data;
    };
} // namespace Loom
