#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>
#include <imgui_internal.h>

#pragma message("Using ImGui version: " IMGUI_VERSION)

namespace Arc
{
    void EditorLayer::Begin()
    {
        m_Dockspace.Begin();
    }

    void EditorLayer::Render(unsigned int framebufferTexture)
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ImGui::MenuItem("New");
                ImGui::MenuItem("Open");
                ImGui::MenuItem("Save");
                ImGui::Separator();
                ImGui::MenuItem("Exit");
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Edit"))
            {
                ImGui::MenuItem("Undo");
                ImGui::MenuItem("Redo");
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("View"))
            {
                ImGui::MenuItem("Viewport");
                ImGui::MenuItem("Hierarchy");
                ImGui::MenuItem("Inspector");
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help"))
            {
                ImGui::MenuItem("About");
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        m_ViewportPanel.Render(framebufferTexture);
        m_HierarchyPanel.Render();
        m_InspectorPanel.Render();
        m_ConsolePanel.Render();
    }

    void EditorLayer::End()
    {
        m_Dockspace.End();
    }
}