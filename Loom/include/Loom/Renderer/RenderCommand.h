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

    private:
        static std::unique_ptr<RendererAPI> s_RendererAPI;
    };
} // namespace Loom
