#pragma once

#include "Loom/Renderer/RendererAPI.h"

namespace Loom
{
    class OpenGLRendererAPI final : public RendererAPI
    {
    public:
        void SetClearColor(float r, float g, float b, float a) override;
        void Clear() override;

        void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount) override;
    };
} // namespace Loom
