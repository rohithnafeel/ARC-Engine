#pragma once

#include "Arc/Renderer/Texture2D.h"

#include <glm/glm.hpp>
#include <memory>

namespace Arc
{
    struct SpriteRenderer
    {
        std::shared_ptr<Texture2D> Texture = nullptr;

        glm::vec4 Tint =
        {
            1.0f,
            1.0f,
            1.0f,
            1.0f
        };
    };
}