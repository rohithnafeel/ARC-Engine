#pragma once

namespace Arc
{
    class EditorLayer
    {
    public:
        void Begin();
        void Render(unsigned int framebufferTexture);
        void End();
    };
}