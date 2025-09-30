#include "Loom/Renderer/VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Loom
{
    Ref<VertexArray> VertexArray::Create()
    {
        return CreateRef<OpenGLVertexArray>();
    }
} // namespace Loom
