#include "Loom/Core/Application.h"
#include <iostream>

namespace Loom
{
    Application::Application()
    {
        m_Window = Window::Create();
        m_Window->SetEventCallback([this](const Event& e) { OnEvent(e); });
    }

    Application::~Application() = default;

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(const Event& e)
    {
        if (e.GetEventType() == EventType::WindowClose)
        {
            m_Running = false;
        }
    }
} // namespace Loom
