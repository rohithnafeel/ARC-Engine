#pragma once

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
    };
}