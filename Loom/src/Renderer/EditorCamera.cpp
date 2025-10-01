#include "Loom/Renderer/EditorCamera.h"
#include "Loom/Core/Input.h"
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace Loom
{
    EditorCamera::EditorCamera(float fov, float aspectRatio, float nearClip, float farClip)
        : m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)
    {
        RecalculateProjection();
        RecalculateView();
    }

    void EditorCamera::OnUpdate(float ts)
    {
        glm::vec2 mouse = Input::GetMousePosition();
        glm::vec2 delta = (mouse - m_InitialMousePosition) * 0.003f;
        m_InitialMousePosition = mouse;

        if (Input::IsMouseButtonPressed(Mouse::Right))
        {
            // Orbit around the focal point
            m_Yaw += delta.x;
            m_Pitch += delta.y;
        }
        else if (Input::IsMouseButtonPressed(Mouse::Middle))
        {
            // Pan
            auto speed = PanSpeed();
            m_FocalPoint += -GetRightDirection() * delta.x * speed.x * m_Distance;
            m_FocalPoint += GetUpDirection() * delta.y * speed.y * m_Distance;
        }

        if (Input::IsKeyPressed(Key::LShift))
            m_Distance -= delta.y * ZoomSpeed();

        RecalculateView();
    }

    void EditorCamera::OnEvent(Event& e)
    {
    }

    void EditorCamera::SetViewportSize(float width, float height)
    {
        m_ViewportSize = { width, height };
        m_AspectRatio = width / height;
        RecalculateProjection();
    }

    void EditorCamera::RecalculateProjection()
    {
        m_Projection = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
    }

    void EditorCamera::RecalculateView()
    {
        m_Position = CalculatePosition();

        glm::quat orientation = GetOrientation();
        glm::mat4 rotation = glm::toMat4(orientation);
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), m_Position);

        m_ViewMatrix = glm::inverse(translation * rotation);
    }

    glm::vec3 EditorCamera::GetUpDirection() const
    {
        return glm::rotate(GetOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    glm::vec3 EditorCamera::GetRightDirection() const
    {
        return glm::rotate(GetOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
    }

    glm::vec3 EditorCamera::GetFowardDirection() const
    {
        return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
    }

    glm::quat EditorCamera::GetOrientation() const
    {
        return { glm::vec3(-m_Pitch, -m_Yaw, 0.0f) };
    }

    glm::vec3 EditorCamera::CalculatePosition() const
    {
        return m_FocalPoint - GetFowardDirection() * m_Distance;
    }

    glm::vec2 EditorCamera::PanSpeed() const
    {
        float x = std::min(m_ViewportSize.x / 1000.0f, 2.4f);
        float xFactor = 0.0366f * (x * x) - 0.1778f * x + 0.3021f;

        float y = std::min(m_ViewportSize.y / 1000.0f, 2.4f);
        float yFactor = 0.0366f * (y * y) - 0.1778f * y + 0.3021f;

        return glm::vec2{ xFactor, yFactor };
    }

    float EditorCamera::ZoomSpeed() const
    {
        float distance = m_Distance * 0.2f;
        distance = std::max(distance, 0.1f);
        float speed = distance * distance;
        return std::min(speed, 100.0f);
    }
} // namespace Loom
