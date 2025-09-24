#pragma once

#include "Loom/Core/Application.h"
#include "Loom/Core/Log.h"

#ifdef LOOM_PLATFORM_GLFW

extern Loom::Application* Loom::CreateApplication();

int main(int argc, char** argv)
{
    Loom::Log::Init();

    const auto app = Loom::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
