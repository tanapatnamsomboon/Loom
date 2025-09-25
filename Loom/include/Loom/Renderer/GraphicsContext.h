#pragma once

#include "Loom/Core/Base.h"

namespace Loom
{
    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static std::unique_ptr<GraphicsContext> Create(void* window);
    };
} // namespace Loom
