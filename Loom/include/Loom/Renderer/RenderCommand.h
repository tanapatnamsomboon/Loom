#pragma once
#include "Loom/Renderer/RendererAPI.h"

namespace Loom
{
    class RenderCommand
    {
    public:
        static void SetClearColor(float r, float g, float b, float a)
        {
            s_RendererAPI->SetClearColor(r, g, b, a);
        }

        static void Clear()
        {
            s_RendererAPI->Clear();
        }

        static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0)
        {
            s_RendererAPI->DrawIndexed(vertexArray, indexCount);
        }

    private:
        static std::unique_ptr<RendererAPI> s_RendererAPI;
    };
} // namespace Loom
