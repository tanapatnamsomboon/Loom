#pragma once

#include "Loom/Core/Window.h"
#include "Loom/Events/Event.h"

namespace Loom
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(const Event& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
} // namespace Loom
