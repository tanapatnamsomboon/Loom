#include "Loom/Renderer/RendererAPI.h"
#include "Loom/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Loom
{
    RendererAPI::API RendererAPI::s_API = API::OpenGL;

    std::unique_ptr<RendererAPI> RendererAPI::Create()
    {
        switch (s_API)
        {
            case API::OpenGL: return std::make_unique<OpenGLRendererAPI>();
            case API::None:   return nullptr;
        }
        return nullptr;
    }
} // namespace Loom
