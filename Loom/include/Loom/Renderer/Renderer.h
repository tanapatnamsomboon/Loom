#pragma once

#include "Loom/Renderer/VertexArray.h"
#include "Loom/Renderer/Shader.h"

namespace Loom
{
    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray);
    };
} // namespace Loom
