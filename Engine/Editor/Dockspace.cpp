#include "Dockspace.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Arc
{
    void Dockspace::Begin()
    {
        ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_MenuBar |
            ImGuiWindowFlags_NoDocking;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();

        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        windowFlags |= ImGuiWindowFlags_NoTitleBar;
        windowFlags |= ImGuiWindowFlags_NoCollapse;
        windowFlags |= ImGuiWindowFlags_NoResize;
        windowFlags |= ImGuiWindowFlags_NoMove;
        windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        windowFlags |= ImGuiWindowFlags_NoNavFocus;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        ImGui::Begin("DockSpace", nullptr, windowFlags);

        ImGui::PopStyleVar(2);

        ImGuiID dockspaceID = ImGui::GetID("ArcDockspace");

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