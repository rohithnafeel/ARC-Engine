#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>
#include <imgui_internal.h>


#pragma message("Using ImGui version: " IMGUI_VERSION)

namespace Arc
{
    void EditorLayer::Begin()
    {
    }

    void EditorLayer::Render(unsigned int framebufferTexture)
    {

        ImGuiWindowFlags window_flags =
            ImGuiWindowFlags_MenuBar |
            ImGuiWindowFlags_NoDocking;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();

        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        window_flags |= ImGuiWindowFlags_NoNavFocus;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        ImGui::Begin("DockSpace", nullptr, window_flags);

        ImGui::PopStyleVar(2);

        ImGuiID dockspaceID = ImGui::GetID("ArcDockSpace");

        ImGui::DockSpace(
            dockspaceID,
            ImVec2(0.0f, 0.0f),
            ImGuiDockNodeFlags_None
        );

        static bool firstTime = true;

if (firstTime)
{
    firstTime = false;

    ImGui::DockBuilderRemoveNode(dockspaceID);
    ImGui::DockBuilderAddNode(
        dockspaceID,
        ImGuiDockNodeFlags_DockSpace
    );

    ImGui::DockBuilderSetNodeSize(
        dockspaceID,
        viewport->WorkSize
    );

    ImGuiID dock_main = dockspaceID;

    ImGuiID dock_left;
    ImGuiID dock_right;
    ImGuiID dock_bottom;

}
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

        // Close DockSpace
        ImGui::End();
    }

    void EditorLayer::End()
    {
    }
}