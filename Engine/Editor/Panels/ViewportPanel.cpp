#include "ViewportPanel.h"
#include "Arc/Renderer/Framebuffer.h"

#include <imgui.h>

namespace Arc
{
    void ViewportPanel::Render(Framebuffer& framebuffer)
    {
        ImGui::Begin("Viewport");

        m_ViewportSize = ImGui::GetContentRegionAvail();

        if ((unsigned int)m_ViewportSize.x != framebuffer.GetWidth() ||
            (unsigned int)m_ViewportSize.y != framebuffer.GetHeight())
        {
            framebuffer.Resize(
                (unsigned int)m_ViewportSize.x,
                (unsigned int)m_ViewportSize.y
            );
        }

        ImGui::Image(
            (ImTextureID)(intptr_t)framebuffer.GetColorAttachment(),
            m_ViewportSize,
            ImVec2(0, 1),
            ImVec2(1, 0)
        );

        ImGui::End();
    }
}