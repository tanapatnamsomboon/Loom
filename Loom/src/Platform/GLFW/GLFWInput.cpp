#include "Platform/GLFW/GLFWInput.h"
#include "Loom/Core/Input.h"
#include "Loom/Core/Application.h"
#include "Loom/Core/Window.h"
#include <GLFW/glfw3.h>

namespace Loom
{
    [[nodiscard]] bool GLFWInput::IsKeyPressedImpl(const KeyCode key) const
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        const auto state = glfwGetKey(window, key);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    [[nodiscard]] bool GLFWInput::IsMouseButtonPressedImpl(const MouseCode button) const
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        const auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    [[nodiscard]] glm::vec2 GLFWInput::GetMousePositionImpl() const
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return glm::vec2{ static_cast<float>(x), static_cast<float>(y) };
    }
} // namespace Loom
