#pragma once
#include "Window.h"

namespace Loom
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
} // namespace Loom
