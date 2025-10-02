#pragma once

#include "Loom/Renderer/SceneCamera.h"
#include "Loom/Renderer/VertexArray.h"
#include "Loom/Renderer/Shader.h"
#include <glm/glm.hpp>
#include <string>
#include <utility>

namespace Loom
{
    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        explicit TagComponent(std::string tag)
            : Tag(std::move(tag))
        {
        }
    };

    struct TransformComponent
    {
        glm::vec3 Translation{0.0f};
        glm::vec3 Rotation{0.0f};
        glm::vec3 Scale{1.0f};

        TransformComponent() = default;
        explicit TransformComponent(const glm::vec3& t)
            : Translation(t)
        {
        }
    };

    struct CameraComponent
    {
        SceneCamera Camera;
        bool Primary = true;
        bool FixedAspectRatio = false;

        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
        explicit CameraComponent(SceneCamera  camera)
            : Camera(std::move(camera))
        {
        }
    };

    struct MeshComponent
    {
        Ref<VertexArray> VertexArrayRef;
        Ref<Shader> ShaderRef;

        MeshComponent() = default;
        MeshComponent(const MeshComponent&) = default;
        MeshComponent(const Ref<VertexArray>& vao, const Ref<Shader>& shader)
            : VertexArrayRef(vao), ShaderRef(shader)
        {
        }
    };
} // namespace Loom
