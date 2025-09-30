#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include <glad/gl.h>

namespace Loom
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
    {
        Bind();
        vertexBuffer->Bind();

        glEnableVertexAttribArray(m_VertexBufferIndex);
        glVertexAttribPointer(m_VertexBufferIndex, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
        m_VertexBufferIndex++;

        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
    {
        Bind();
        indexBuffer->Bind();
        m_IndexBuffer = indexBuffer;
    }
} // namespace Loom
