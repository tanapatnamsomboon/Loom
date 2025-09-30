#include "Loom/Renderer/Buffer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Loom
{
    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
    {
        return CreateRef<OpenGLVertexBuffer>(vertices, size);
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        return CreateRef<OpenGLIndexBuffer>(indices, count);
    }
} // namespace Loom
