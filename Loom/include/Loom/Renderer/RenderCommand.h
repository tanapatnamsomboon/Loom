#pragma once
#include "Loom/Renderer/RendererAPI.h"

namespace Loom
{
    class RenderCommand
    {
    public:
        static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
        {
            s_RendererAPI->SetViewport(x, y, width, height);
        }

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
