#pragma once

#include <imgui.h>

namespace Arc
{
    class Framebuffer;

    class ViewportPanel
    {
    public:
        void Render(Framebuffer& framebuffer);

        const ImVec2& GetViewportSize() const
        {
            return m_ViewportSize;
        }

    private:
        ImVec2 m_ViewportSize = ImVec2(0.0f, 0.0f);
    };
}