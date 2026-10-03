#include "Arc/Editor/EditorLayer.h"

#include "Arc/Renderer/Renderer.h"

#include "Core/Application.h"
#include "Core/Input.h"

#include <imgui.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>
#include <memory>

namespace Arc
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer"),
          m_Camera(
              -10.0f,
              10.0f,
              -5.625f,
              5.625f
          )
    {
    }

    void EditorLayer::OnAttach()
    {
        std::cout
            << "EditorLayer Attached\n";

        m_Framebuffer =
            std::make_unique<Framebuffer>(
                1280,
                720
            );

        std::cout
            << "Editor Framebuffer Created\n";
    }

    void EditorLayer::OnDetach()
    {
        std::cout
            << "EditorLayer Detached\n";

        m_Framebuffer.reset();
    }

    void EditorLayer::OnUpdate()
    {
        if (!m_Framebuffer)
            return;

        // -----------------------------
        // Delta Time
        // -----------------------------

        float deltaTime =
            Application::GetDeltaTime();

        // -----------------------------
        // Camera Movement
        // -----------------------------

        float cameraSpeed = 5.0f;

        glm::vec3 cameraPosition =
            m_Camera.GetPosition();

        if (Input::IsKeyPressed(GLFW_KEY_W))
        {
            cameraPosition.y +=
                cameraSpeed * deltaTime;
        }

        if (Input::IsKeyPressed(GLFW_KEY_S))
        {
            cameraPosition.y -=
                cameraSpeed * deltaTime;
        }

        if (Input::IsKeyPressed(GLFW_KEY_A))
        {
            cameraPosition.x -=
                cameraSpeed * deltaTime;
        }

        if (Input::IsKeyPressed(GLFW_KEY_D))
        {
            cameraPosition.x +=
                cameraSpeed * deltaTime;
        }

        m_Camera.SetPosition(
            cameraPosition
        );

        // -----------------------------
        // Scene Rendering
        // -----------------------------

        m_Framebuffer->Bind();

        Renderer::BeginFrame();

        Renderer::SetCamera(
            m_Camera.GetViewProjectionMatrix()
        );

        Renderer::DrawTriangle();

        Renderer::EndFrame();

        m_Framebuffer->Unbind();
    }

    void EditorLayer::OnImGuiRender()
    {
        m_Dockspace.Begin();

        // -----------------------------
        // Main Menu Bar
        // -----------------------------

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

        // -----------------------------
        // Editor Panels
        // -----------------------------

        m_ViewportPanel.Render(
            *m_Framebuffer
        );

        m_HierarchyPanel.Render();

        m_InspectorPanel.Render();

        m_ConsolePanel.Render();

        // -----------------------------
        // End Dockspace
        // -----------------------------

        m_Dockspace.End();
    }
}