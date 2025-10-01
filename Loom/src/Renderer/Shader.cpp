#include "Loom/Renderer/Shader.h"
#include "Loom/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Loom
{
    Ref<Shader> Shader::Create(const std::string& filePath)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::None: LOOM_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(filePath);
        }
        LOOM_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::None: LOOM_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
        }
        LOOM_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
} // namespace Loom
