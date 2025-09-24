#pragma once

#include "Loom/Core/Application.h"

#ifdef LOOM_PLATFORM_GLFW

extern Loom::Application* Loom::CreateApplication();

int main(int argc, char** argv)
{
    const auto app = Loom::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
