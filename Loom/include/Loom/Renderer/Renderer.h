#pragma once

#include "Loom/Renderer/VertexArray.h"
#include "Loom/Renderer/Shader.h"
#include "Loom/Renderer/Camera.h"
#include "Loom/Renderer/EditorCamera.h"

namespace Loom
{
    class Renderer
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(const Camera& camera, const glm::mat4& transform);
        static void BeginScene(const EditorCamera& camera);
        static void EndScene();

        static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };
        static Scope<SceneData> s_SceneData;
    };
} // namespace Loom
