#pragma once

#include "Loom/Core/Base.h"
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

        void OnUpdate();

    private:
        entt::registry m_Registry;

        friend class Entity;
        friend class ::SceneHierarchyPanel;
    };
} // namespace Loom
