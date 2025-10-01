#pragma once

#include "Loom/Renderer/Framebuffer.h"

namespace Loom
{
    class OpenGLFramebuffer final : public Framebuffer
    {
    public:
        explicit OpenGLFramebuffer(const FramebufferSpecification& spec);
        ~OpenGLFramebuffer() override;

        void Bind() override;
        void Unbind() override;

        void Resize(uint32_t width, uint32_t height) override;
        [[nodiscard]] uint32_t GetColorAttachmentRendererID() const override;

    private:
        void Invalidate();

        uint32_t m_RendererID = 0;
        uint32_t m_ColorAttachment = 0;
        uint32_t m_DepthAttachment = 0;

        FramebufferSpecification m_Specification;
    };
} // namespace Loom
