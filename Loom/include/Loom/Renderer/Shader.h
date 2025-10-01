#pragma once

#include "Loom/Core/Base.h"
#include <string>
#include <glm/glm.hpp>

namespace Loom
{
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

        static Ref<Shader> Create(const std::string& filePath);
        static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
} // namespace Loom
