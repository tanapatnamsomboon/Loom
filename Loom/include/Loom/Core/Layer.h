#pragma once

#include "Loom/Events/Event.h"
#include "Loom/Core/Timestep.h"
#include <string>
#include <utility>

namespace Loom
{
    class Layer
    {
    public:
        explicit Layer(std::string name = "Layer")
            : m_DebugName(std::move(name))
        {
        }
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestep ts) {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        [[nodiscard]] const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
} // namespace Loom
