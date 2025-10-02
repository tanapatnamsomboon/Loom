#include "Loom/Scene/Scene.h"
#include "Loom/Scene/Entity.h"
#include "Loom/Renderer/Renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

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

    void Scene::OnUpdateEditor(Timestep ts, EditorCamera& camera)
    {
        Renderer::BeginScene(camera);

        auto view = m_Registry.view<TransformComponent, MeshComponent>();
        for (auto entity : view)
        {
            auto [transform, mesh] = view.get<TransformComponent, MeshComponent>(entity);
            glm::mat4 transformMat = glm::translate(glm::mat4(1.0f), transform.Translation)
                                   * glm::toMat4(glm::quat(transform.Rotation))
                                   * glm::scale(glm::mat4(1.0f), transform.Scale);

            Renderer::Submit(mesh.ShaderRef, mesh.VertexArrayRef, transformMat);
        }

        Renderer::EndScene();
    }

    void Scene::OnUpdateRuntime(Timestep ts)
    {
        Camera* mainCamera = nullptr;
        glm::mat4 cameraTransform;

        auto view = m_Registry.view<TransformComponent, CameraComponent>();
        for (auto entity : view)
        {
            auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
            if (camera.Primary)
            {
                mainCamera = &camera.Camera;
                cameraTransform = glm::translate(glm::mat4(1.0f), transform.Translation)
                                * glm::toMat4(glm::quat(transform.Rotation))
                                * glm::scale(glm::mat4(1.0f), transform.Scale);
                break;
            }
        }

        if (mainCamera)
        {
            Renderer::BeginScene(*mainCamera, cameraTransform);

            Renderer::EndScene();
        }
    }
} // namespace Loom
