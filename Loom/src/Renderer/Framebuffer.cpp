#include "Loom/Renderer/Framebuffer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Loom
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
    {
        return CreateRef<OpenGLFramebuffer>(spec);
        return nullptr;
    }
}
