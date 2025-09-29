#pragma once

#include "Loom/Renderer/Framebuffer.h"

namespace Loom
{
    class OpenGLFramebuffer final : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        ~OpenGLFramebuffer();

        void Bind() override;
        void Unbind() override;

        [[nodiscard]] uint32_t GetColorAttachmentRendererID() const override;

    private:
        uint32_t m_RendererID = 0;
        uint32_t m_ColorAttachment = 0;
        uint32_t m_DepthAttachment = 0;

        FramebufferSpecification m_Specification;
    };
} // namespace Loom
