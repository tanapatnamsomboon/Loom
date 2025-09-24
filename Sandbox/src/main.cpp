#include <Loom/Core/Application.h>
#include <Loom/Core/EntryPoint.h>
#include <Loom/Events/KeyEvent.h>
#include <print>

class SandboxLayer final : public Loom::Layer
{
public:
    ~SandboxLayer() override = default;

    void OnEvent(Loom::Event& event) override
    {
        Loom::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Loom::KeyPressedEvent>(LOOM_BIND_EVENT_FN(OnKeyPressed));
    }

private:
    bool OnKeyPressed(Loom::KeyPressedEvent& e)
    {
        std::println("{}", e.ToString());
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

