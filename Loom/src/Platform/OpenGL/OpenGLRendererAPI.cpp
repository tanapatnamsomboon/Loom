#include "Platform/OpenGL/OpenGLRendererAPI.h"
#include <glad/gl.h>

namespace Loom
{
    void OpenGLRendererAPI::SetClearColor(const float r, const float g, const float b, const float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
} // namespace Loom
