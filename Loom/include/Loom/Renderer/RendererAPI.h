#pragma once
#include "Loom/Core/Base.h"

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

        virtual void SetClearColor(float r, float g, float b, float a) = 0;
        virtual void Clear() = 0;

        static std::unique_ptr<RendererAPI> Create();

        static API GetAPI() { return s_API; }

    private:
        static API s_API;
    };
} // namespace Loom
