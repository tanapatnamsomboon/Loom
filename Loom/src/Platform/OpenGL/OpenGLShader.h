#pragma once

#include "Loom/Renderer/Shader.h"

namespace Loom
{
    class OpenGLShader final : public Shader
    {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~OpenGLShader() override;

        void Bind() const override;
        void Unbind() const override;

    private:
        uint32_t m_RendererID;
    };
} // namespace Loom
