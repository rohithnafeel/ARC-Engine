#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>
#include <iostream>

namespace Arc
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer")
    {
    }

    void EditorLayer::OnAttach()
    {
        std::cout << "EditorLayer Attached\n";
    }

    void EditorLayer::OnDetach()
    {
        std::cout << "EditorLayer Detached\n";
    }

    void EditorLayer::OnUpdate()
    {
    }

    void EditorLayer::OnImGuiRender()
    {
        m_Dockspace.Begin();

        // Main menu bar
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
                ImGui::MenuItem("Console");

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help"))
            {
                ImGui::MenuItem("About");

                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        // Editor panels
        m_HierarchyPanel.Render();
        m_InspectorPanel.Render();
        m_ConsolePanel.Render();

        m_Dockspace.End();
    }
}