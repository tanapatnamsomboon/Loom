#include "Loom/Core/Input.h"
#include "Platform/GLFW/GLFWInput.h"

namespace Loom
{
    std::unique_ptr<Input> Input::s_Instance;

    void Input::Init()
    {
#   ifdef LOOM_PLATFORM_GLFW
        s_Instance = std::make_unique<GLFWInput>();
#   else
        static_assert(false, "No input system platform defined!");
        s_Instance = nullptr;
#   endif
    }
} // namespace Loom
