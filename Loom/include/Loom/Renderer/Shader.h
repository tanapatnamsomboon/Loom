#pragma once

#include "Loom/Core/Base.h"
#include <string>

namespace Loom
{
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
} // namespace Loom
