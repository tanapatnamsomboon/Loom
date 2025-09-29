#include "Loom/Scene/Scene.h"
#include "Loom/Scene/Entity.h"

namespace Loom
{
    Scene::Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity = { m_Registry.create(), this };
        entity.AddComponent<TagComponent>(name.empty() ? "Entity" : name);
        entity.AddComponent<TransformComponent>();
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        m_Registry.destroy(entity);
    }

    void Scene::OnUpdate()
    {
        auto view = m_Registry.view<TransformComponent>();
        for (auto e : view)
        {
            auto& tc = view.get<TransformComponent>(e);
        }
    }
} // namespace Loom
