#include "Platform/GLFW/GLFWWindow.h"

#include "Loom/Core/Assert.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Loom/Events/ApplicationEvent.h"

#include "Loom/Events/KeyEvent.h"

namespace Loom
{
    static bool s_GLFWInitialized = false;

    GLFWWindow::GLFWWindow(const WindowProps& props)
    {
        Init(props);
    }

    GLFWWindow::~GLFWWindow()
    {
        Shutdown();
    }

    void GLFWWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if (!s_GLFWInitialized)
        {
            if (!glfwInit())
            {
                LOOM_CORE_ASSERT(false, "Failed to initialize GLFW!");
                return;
            }
            s_GLFWInitialized = true;
        }

        // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

        m_Window = glfwCreateWindow(
            static_cast<int>(props.Width),
            static_cast<int>(props.Height),
            m_Data.Title.c_str(),
            nullptr, nullptr);
        if (!m_Window)
        {
            LOOM_CORE_ASSERT(false, "Failed to create GLFW window!");
            return;
        }
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);

        m_Context = std::make_unique<OpenGLContext>(m_Window);
        m_Context->Init();

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            const WindowData& data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            const WindowData& data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));

            if (action == GLFW_PRESS)
            {
                KeyPressedEvent event(key);
                data.EventCallback(event);
            }
            else if (action == GLFW_RELEASE)
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
            }
        });
    }

    void GLFWWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void GLFWWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
} // namespace Loom
