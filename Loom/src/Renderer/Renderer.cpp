#include "Loom/Renderer/Renderer.h"
#include "Loom/Renderer/RenderCommand.h"

namespace Loom
{
    Scope<Renderer::SceneData> Renderer::s_SceneData = CreateScope<Renderer::SceneData>();

    void Renderer::Init()
    {
    }

    void Renderer::Shutdown()
    {
    }

    void Renderer::BeginScene(const Camera& camera, const glm::mat4& transform)
    {
        s_SceneData->ViewProjectionMatrix = camera.GetProjection() * glm::inverse(transform);
    }

    void Renderer::BeginScene(const EditorCamera& camera)
    {
        s_SceneData->ViewProjectionMatrix = camera.GetViewProjection();
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
    {
        shader->Bind();
        shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
        shader->SetMat4("u_Transform", transform);

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
} // namespace Loom
