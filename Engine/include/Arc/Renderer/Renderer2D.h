#pragma once

#include "Arc/Math/Transform.h"
#include "Arc/Renderer/Texture2D.h"

#include <glm/glm.hpp>

namespace Arc
{
    class Renderer2D
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(
            const glm::mat4& viewProjection
        );

        static void EndScene();

        static void DrawQuad(
    const Transform& transform,
    const Texture2D& texture,
    const glm::vec4& tint
);

static void DrawQuad(
    const Transform& transform,
    const glm::vec4& color
);
    };
}