#pragma once

#include "Loom/Renderer/Shader.h"
#include <glad/gl.h>
#include <unordered_map>

namespace Loom
{
    class OpenGLShader final : public Shader
    {
    public:
        OpenGLShader(const std::string& filepath);
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~OpenGLShader() override;

        void Bind() const override;
        void Unbind() const override;

        void SetMat4(const std::string& name, const glm::mat4& value) override;

    private:
        std::string ReadFile(const std::string& filepath);
        std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
        void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);

    private:
        uint32_t m_RendererID;
    };
} // namespace Loom
