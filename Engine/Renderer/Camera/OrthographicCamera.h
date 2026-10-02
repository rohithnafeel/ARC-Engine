#pragma once

#include <glm/glm.hpp>

namespace Arc
{
    class OrthographicCamera
    {
    public:

        OrthographicCamera(
            float left,
            float right,
            float bottom,
            float top
        );

        void SetPosition(const glm::vec3& position);
        void SetRotation(float rotation);

        const glm::vec3& GetPosition() const;
        float GetRotation() const;

        const glm::mat4& GetViewProjectionMatrix() const;

    private:

        void RecalculateViewMatrix();

    private:

        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjectionMatrix;

        glm::vec3 m_Position = glm::vec3(0.0f);
        float m_Rotation = 0.0f;
    };
}