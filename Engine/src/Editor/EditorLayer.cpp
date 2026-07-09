#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>
#pragma message("Using ImGui version: " IMGUI_VERSION)

namespace Arc
{
    void EditorLayer::Begin()
    {
    }

    void EditorLayer::Render()
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

        ImGui::Begin("Viewport");

        ImGui::Text("Arc Engine");
        ImGui::Separator();
        ImGui::Text("OpenGL Renderer Running");
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

        ImGui::End();

        ImGui::Begin("Hierarchy");
        ImGui::BulletText("Camera");
        ImGui::BulletText("Triangle");
        ImGui::End();

        ImGui::Begin("Inspector");
        ImGui::Text("No object selected.");
        ImGui::End();

        ImGui::Begin("Console");
        ImGui::Text("Arc Engine started successfully.");
        ImGui::End();
    }

    void EditorLayer::End()
    {
    }
}