#pragma once

#include "Base.h"
#include "Loom/Core/Window.h"
#include "Loom/Core/LayerStack.h"
#include "Loom/Events/ApplicationEvent.h"
#include "Loom/ImGui/ImGuiLayer.h"

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

        static Application& Get() { return *s_Instance; }
        [[nodiscard]] Window& GetWindow() const { return *m_Window; }

        void Close();

    private:
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        Scope<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        ImGuiLayer* m_ImGuiLayer;

    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
} // namespace Loom
