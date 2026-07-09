#include "ViewportPanel.h"

#include <imgui.h>

namespace Arc
{
    void ViewportPanel::Render(unsigned int framebufferTexture)
    {
        ImGui::Begin("Viewport");

        ImVec2 viewportSize = ImGui::GetContentRegionAvail();

        ImGui::Image(
            (ImTextureID)(intptr_t)framebufferTexture,
            viewportSize,
            ImVec2(0, 1),
            ImVec2(1, 0)
        );

        ImGui::End();
    }
}