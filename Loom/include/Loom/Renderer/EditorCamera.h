#pragma once

#include "Loom/Renderer/Camera.h"
#include <glm/glm.hpp>

namespace Loom
{
    class EditorCamera final : public Camera
    {
    public:
        EditorCamera(float fov, float aspectRatio, float nearClip, float farClip);

        void OnUpdate(float ts);
        void OnEvent(class Event& e);

        void SetViewportSize(float width, float height);

        const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
        glm::mat4 GetViewProjection() const { return m_Projection * m_ViewMatrix; }

    private:
        void RecalculateProjection();
        void RecalculateView();

        glm::vec3 GetUpDirection() const;
        glm::vec3 GetRightDirection() const;
        glm::vec3 GetFowardDirection() const;
        glm::quat GetOrientation() const;

        glm::vec3 CalculatePosition() const;

        glm::vec2 PanSpeed() const;
        float ZoomSpeed() const;

    private:
        float m_FOV, m_AspectRatio, m_NearClip, m_FarClip;

        glm::mat4 m_ViewMatrix{ 1.0f };
        glm::vec3 m_Position{ 0.0f, 0.0f, 5.0f };
        glm::vec3 m_FocalPoint{ 0.0f };

        float m_Distance = 10.0f;
        float m_Pitch = 0.0f, m_Yaw = 0.0f;

        glm::vec2 m_ViewportSize = { 1280.0f, 720.0f };
        glm::vec2 m_InitialMousePosition = { 0.0f, 0.0f };
    };
} // namespace Loom
