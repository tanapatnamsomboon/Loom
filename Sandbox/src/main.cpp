#include <Loom/Core/Application.h>
#include <Loom/Core/EntryPoint.h>
#include <Loom/Events/KeyEvent.h>

#include "Loom/Renderer/RenderCommand.h"

class SandboxLayer final : public Loom::Layer
{
public:
    ~SandboxLayer() override = default;

    void OnUpdate() override
    {
        Loom::RenderCommand::SetClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        Loom::RenderCommand::Clear();
    }

    void OnEvent(Loom::Event& event) override
    {
        Loom::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Loom::KeyPressedEvent>(LOOM_BIND_EVENT_FN(OnKeyPressed));
    }

private:
    bool OnKeyPressed(Loom::KeyPressedEvent& e)
    {
        if (Loom::Input::IsKeyPressed(Loom::Key::Space))
        {
            LOOM_INFO("Spacebar is pressed!");
        }
        return true;
    }
};

class SandboxApp final : public Loom::Application
{
public:
    SandboxApp()
    {
        PushLayer(new SandboxLayer());
    }
};

Loom::Application *Loom::CreateApplication()
{
    return new SandboxApp();
}

