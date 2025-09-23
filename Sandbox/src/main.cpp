#include "Loom/Core/Application.h"
#include <print>

class Sandbox final : public Loom::Application
{
public:
    Sandbox()
    {
        std::println("Sandbox app created!");
    }
};

int main()
{
    Sandbox app;
    app.Run();

    return 0;
}
