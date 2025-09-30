#pragma once

#include "Loom/Renderer/Buffer.h"

namespace Loom
{
    class OpenGLVertexBuffer final : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        ~OpenGLVertexBuffer() override;

        void Bind() const override;
        void Unbind() const override;

    private:
        uint32_t m_RendererID{};
    };

    class OpenGLIndexBuffer final : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        ~OpenGLIndexBuffer() override;

        void Bind() const override;
        void Unbind() const override;

        [[nodiscard]] uint32_t GetCount() const override { return m_Count; }

    private:
        uint32_t m_RendererID{};
        uint32_t m_Count;
    };
} // namespace Loom
