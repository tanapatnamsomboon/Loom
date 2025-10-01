#pragma once

#include "Loom/Renderer/RendererAPI.h"

namespace Loom
{
    class OpenGLRendererAPI final : public RendererAPI
    {
    public:
        void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        void SetClearColor(float r, float g, float b, float a) override;
        void Clear() override;

        void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount) override;
    };
} // namespace Loom
