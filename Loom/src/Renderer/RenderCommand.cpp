#include "Loom/Renderer/RenderCommand.h"

namespace Loom
{
    std::unique_ptr<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
} // namespace Loom
