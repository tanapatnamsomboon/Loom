#pragma once

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
        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
    };
} // namespace Loom
