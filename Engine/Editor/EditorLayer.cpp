#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>
#pragma message("Using ImGui version: " IMGUI_VERSION)

namespace Arc
{
    void EditorLayer::Begin()
    {
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

    ImGui::Begin("Viewport");

    ImVec2 viewportSize = ImGui::GetContentRegionAvail();

    ImGui::Image(
        (ImTextureID)(intptr_t)framebufferTexture,
        viewportSize,
        ImVec2(0, 1),
        ImVec2(1, 0)
    );

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