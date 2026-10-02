#pragma once

#include <glm/glm.hpp>

namespace Arc
{
    class Renderer
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginFrame();
        static void DrawTriangle();
        static void EndFrame();

        static void SetCamera(const glm::mat4& viewProjection);
    };
}