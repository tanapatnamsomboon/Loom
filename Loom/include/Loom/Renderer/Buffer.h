#pragma once

#include "Loom/Core/Base.h"

namespace Loom
{
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        [[nodiscard]] virtual uint32_t GetCount() const = 0;

        static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
    };
} // namespace Loom
