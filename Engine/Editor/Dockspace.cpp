#include "Dockspace.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Arc
{
    void Dockspace::Begin()
    {
        ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_MenuBar |
            ImGuiWindowFlags_NoDocking |
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_NoNavFocus;

        const ImGuiViewport* viewport =
            ImGui::GetMainViewport();

        ImGui::SetNextWindowPos(
            viewport->WorkPos
        );

        ImGui::SetNextWindowSize(
            viewport->WorkSize
        );

        ImGui::SetNextWindowViewport(
            viewport->ID
        );

        ImGui::PushStyleVar(
            ImGuiStyleVar_WindowRounding,
            0.0f
        );

        ImGui::PushStyleVar(
            ImGuiStyleVar_WindowBorderSize,
            0.0f
        );

        ImGui::Begin(
            "DockSpace",
            nullptr,
            windowFlags
        );

        ImGui::PopStyleVar(2);

        ImGuiID dockspaceID =
            ImGui::GetID("ArcDockspace");

        ImGui::DockSpace(
            dockspaceID,
            ImVec2(0.0f, 0.0f),
            ImGuiDockNodeFlags_None
        );
    }

    void Dockspace::End()
    {
        ImGui::End();
    }
}