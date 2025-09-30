#include "Loom/Renderer/Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Loom
{
    Ref<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
    }
} // namespace Loom
