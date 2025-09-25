#pragma once

#include "Loom/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Loom
{
    class OpenGLContext final : public GraphicsContext
    {
    public:
        explicit OpenGLContext(GLFWwindow* windowHandle);

        void Init() override;
        void SwapBuffers() override;

    private:
        GLFWwindow* m_WindowHandle;
    };
} // namespace Loom
