#include "Arc/Editor/EditorLayer.h"
#include "Arc/Renderer/Renderer.h"

#include <imgui.h>
#include <iostream>
#include <memory>

namespace Arc
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer")
    {
    }

    void EditorLayer::OnAttach()
    {
        std::cout << "EditorLayer Attached\n";

        // Create the editor framebuffer
        m_Framebuffer = std::make_unique<Framebuffer>(1280, 720);

        std::cout << "Editor Framebuffer Created\n";
    }

    void EditorLayer::OnDetach()
    {
        std::cout << "EditorLayer Detached\n";

        m_Framebuffer.reset();
    }

    void EditorLayer::OnUpdate()
{
    if (!m_Framebuffer)
        return;

    m_Framebuffer->Bind();

    Renderer::BeginFrame();
    Renderer::DrawTriangle();
    Renderer::EndFrame();

    m_Framebuffer->Unbind();
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

m_ViewportPanel.Render(*m_Framebuffer);
m_HierarchyPanel.Render();
m_InspectorPanel.Render();
m_ConsolePanel.Render();

        m_Dockspace.End();
    }
}