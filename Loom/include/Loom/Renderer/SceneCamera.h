#pragma once

#include "Loom/Renderer/Camera.h"

namespace Loom
{
    class SceneCamera final : public Camera
    {
    public:
        enum class ProjectionType { Perspective = 0, Orthographic = 1 };

    public:
        SceneCamera();

        void SetOrthographic(float size, float nearClip, float farClip);
        void SetPerspective(float fov, float nearClip, float farClip);

        void SetViewportSize(uint32_t width, uint32_t height);

        [[nodiscard]] float GetPerspectiveVerticalFOV() const { return m_PerspectiveFOV; }
        void SetPerspectiveVerticalFOV(float fov) { m_PerspectiveFOV = fov; RecalculateProjection(); }

        [[nodiscard]] float GetPerspectiveNearClip() const { return m_PerspectiveNear; }
        [[nodiscard]] float GetPerspectiveFarClip() const { return m_PerspectiveFar; }

        void SetOrthographicSize(float size) { m_OrthographicSize = size; RecalculateProjection(); }
        [[nodiscard]] float GetOrthographicSize() const { return m_OrthographicSize; }

        [[nodiscard]] ProjectionType GetProjectionType() const { return m_ProjectionType; }
        void SetProjectionType(ProjectionType type) { m_ProjectionType = type; RecalculateProjection(); }

    private:
        void RecalculateProjection();

    private:
        ProjectionType m_ProjectionType = ProjectionType::Orthographic;

        // Perspective
        float m_PerspectiveFOV = glm::radians(45.0f);
        float m_PerspectiveNear = 0.01f, m_PerspectiveFar = 1000.0f;

        // Orthographic
        float m_OrthographicSize = 10.0f;
        float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;

        float m_AspectRatio = 1.0f;
    };
} // namespace Loom
