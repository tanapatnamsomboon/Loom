#include "Application.h"
#include <iostream>

namespace Loom
{
    Application::Application()
    {
        m_Window = Window::Create();
    }

    Application::~Application() = default;

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
} // namespace Loom
