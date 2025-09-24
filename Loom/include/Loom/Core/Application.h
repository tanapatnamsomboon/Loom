#pragma once

#include "Base.h"
#include "Loom/Core/Window.h"
#include "Loom/Core/LayerStack.h"
#include "Loom/Events/ApplicationEvent.h"

namespace Loom
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication();
} // namespace Loom
