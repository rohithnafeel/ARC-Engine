#include "Arc/Math/Transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Arc
{
    glm::mat4 Transform::GetTransform() const
    {
        glm::mat4 transform =
            glm::translate(
                glm::mat4(1.0f),
                Position
            );

        transform =
            glm::rotate(
                transform,
                glm::radians(Rotation),
                glm::vec3(0.0f, 0.0f, 1.0f)
            );

        transform =
            glm::scale(
                transform,
                Scale
            );

        return transform;
    }
}