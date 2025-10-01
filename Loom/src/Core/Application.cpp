#include "Loom/Core/Application.h"
#include "Loom/Core/Timestep.h"
#include "Loom/Renderer/RenderCommand.h"
#include <GLFW/glfw3.h>

namespace Loom
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LOOM_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = Window::Create();
        m_Window->SetEventCallback(LOOM_BIND_EVENT_FN(OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application() = default;

    void Application::Run()
    {
        float lastFrameTime = 0.0f;

        while (m_Running)
        {
            float time = glfwGetTime(); // TODO: Use platform::GetTime() instead
            Timestep timestep = time - lastFrameTime;
            lastFrameTime = time;

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate(timestep);

            m_ImGuiLayer->Begin();
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(LOOM_BIND_EVENT_FN(OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(LOOM_BIND_EVENT_FN(OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            (*it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PopOverlay(layer);
        layer->OnAttach();
    }

    void Application::Close()
    {
        m_Running = false;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        int width = e.GetWidth();
        int height = e.GetHeight();

        if (width == 0 || height == 0)
        {
            m_Minimize = true;
            return false;
        }
        m_Minimize = false;

        RenderCommand::SetViewport(0, 0, width, height);
        return false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
} // namespace Loom
