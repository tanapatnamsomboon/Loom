#define LOOM_INCLUDE_ENTRYPOINT
#include <Loom/Loom.h>
#include "EditorLayer.h"

class EditorApp final : public Loom::Application
{
public:
    EditorApp()
    {
        LOOM_INFO("Loom Editor started!");
        PushLayer(new EditorLayer());
    }
};

Loom::Application *Loom::CreateApplication()
{
    return new EditorApp();
}
