#pragma once

#include "Loom/Renderer/VertexArray.h"

namespace Loom
{
    class OpenGLVertexArray final : public VertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray() override;

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
        void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

        [[nodiscard]] const Ref<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

    private:
        uint32_t m_RendererID;
        uint32_t m_VertexBufferIndex = 0;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
    };
} // namespace Loom
