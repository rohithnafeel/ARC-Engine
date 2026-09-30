#include "ViewportPanel.h"
#include "Arc/Renderer/Framebuffer.h"

#include <imgui.h>
#include <iostream>

namespace Arc
{
    void ViewportPanel::Render(Framebuffer& framebuffer)
    {
        ImGui::Begin("Viewport");

        m_ViewportSize = ImGui::GetContentRegionAvail();

        ImGui::Text(
            "Viewport Size: %.0f x %.0f",
            m_ViewportSize.x,
            m_ViewportSize.y
        );

        ImGui::Text(
            "Framebuffer Size: %u x %u",
            framebuffer.GetWidth(),
            framebuffer.GetHeight()
        );

        ImGui::Text(
            "Texture ID: %u",
            framebuffer.GetColorAttachment()
        );

        if (m_ViewportSize.x > 0.0f &&
            m_ViewportSize.y > 0.0f)
        {
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
        }

        ImGui::End();
    }
}