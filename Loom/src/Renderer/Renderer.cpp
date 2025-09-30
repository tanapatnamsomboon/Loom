#include "Loom/Renderer/Renderer.h"
#include "Loom/Renderer/RenderCommand.h"

namespace Loom
{
    void Renderer::BeginScene()
    {
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray)
    {
        shader->Bind();
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
} // namespace Loom
