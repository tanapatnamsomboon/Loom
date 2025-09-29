#pragma once

#include "Loom/Core/Base.h"

namespace Loom
{
    struct FramebufferSpecification
    {
        uint32_t Width, Height;
    };

    class Framebuffer
    {
    public:
        virtual ~Framebuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        [[nodiscard]] virtual uint32_t GetColorAttachmentRendererID() const = 0;

        static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
    };
} // namespace Loom
