#pragma once
#include "Loom/Core/Base.h"
#include "Loom/Renderer/VertexArray.h"

namespace Loom
{
    class RendererAPI
    {
    public:
        enum class API
        {
            None = 0,
            OpenGL = 1
        };

    public:
        virtual ~RendererAPI() = default;

        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        virtual void SetClearColor(float r, float g, float b, float a) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;

        static std::unique_ptr<RendererAPI> Create();
        static API GetAPI() { return s_API; }

    private:
        static API s_API;
    };
} // namespace Loom
