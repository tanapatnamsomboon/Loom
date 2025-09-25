#include "Platform/OpenGL/OpenGLContext.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Loom
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
    }

    void OpenGLContext::Init()
    {
        if (!gladLoadGL(glfwGetProcAddress))
        {
            return;
        }
        LOOM_CORE_INFO("OpenGL Renderer: {}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        LOOM_CORE_INFO("OpenGL Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
} // namespace Loom
