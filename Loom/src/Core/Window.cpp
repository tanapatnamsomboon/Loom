#include "Window.h"

#ifdef LOOM_PLATFORM_GLFW
#include "Platform/GLFW/GLFWWindow.h"
#endif

namespace Loom
{
    std::unique_ptr<Window> Window::Create(const WindowProps& props)
    {
#   ifdef LOOM_PLATFORM_GLFW
        return std::make_unique<GLFWWindow>(props);
#   else
        static_assert(false, "No windowing platform defined!");
        return nullptr;
#   endif
    }
} // namespace Loom
