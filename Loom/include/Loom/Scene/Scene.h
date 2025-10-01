#pragma once

#include "Loom/Core/Base.h"
#include "Loom/Core/Timestep.h"
#include "Loom/Renderer/EditorCamera.h"
#include <entt/entt.hpp>

class SceneHierarchyPanel;

namespace Loom
{
    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene() = default;

        Entity CreateEntity(const std::string& name = std::string());
        void DestroyEntity(Entity entity);

        void OnUpdateEditor(Timestep ts, EditorCamera& camera);
        void OnUpdateRuntime(Timestep ts);

    private:
        entt::registry m_Registry;

        friend class Entity;
        friend class ::SceneHierarchyPanel;
    };
} // namespace Loom
