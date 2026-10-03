#include "Arc/Editor/EditorLayer.h"

#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Renderer2D.h"
#include "Arc/Math/Transform.h"

#include "Core/Application.h"
#include "Core/Input.h"

#include <imgui.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>
#include <memory>

namespace Arc
{
    // ============================================================
    // Constructor
    // ============================================================

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


    // ============================================================
    // On Attach
    // ============================================================

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


    // ============================================================
    // On Detach
    // ============================================================

    void EditorLayer::OnDetach()
    {
        std::cout
            << "EditorLayer Detached\n";

        m_Framebuffer.reset();
    }


    // ============================================================
    // On Update
    // ============================================================

    void EditorLayer::OnUpdate()
    {
        if (!m_Framebuffer)
            return;


        // --------------------------------------------------------
        // Delta Time
        // --------------------------------------------------------

        float deltaTime =
            Application::GetDeltaTime();

        float cameraSpeed = 5.0f;


        // --------------------------------------------------------
        // Camera Movement
        // --------------------------------------------------------

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


        // --------------------------------------------------------
        // Bind Framebuffer
        // --------------------------------------------------------

        m_Framebuffer->Bind();


        // --------------------------------------------------------
        // Begin Frame
        // --------------------------------------------------------

        Renderer::BeginFrame();


        // --------------------------------------------------------
        // Begin 2D Scene
        // --------------------------------------------------------

        Renderer2D::BeginScene(
            m_Camera.GetViewProjectionMatrix()
        );


        // --------------------------------------------------------
        // Create Quad Transform
        // --------------------------------------------------------

        Transform quadTransform;

        quadTransform.Position =
            { 0.0f, 0.0f, 0.0f };

        quadTransform.Rotation =
            25.0f;

        quadTransform.Scale =
            { 2.0f, 2.0f, 1.0f };


        // --------------------------------------------------------
        // Draw Quad
        // --------------------------------------------------------

        Renderer2D::DrawQuad(
            quadTransform,
            { 1.0f, 0.3f, 0.2f, 1.0f }
        );


        // --------------------------------------------------------
        // End 2D Scene
        // --------------------------------------------------------

        Renderer2D::EndScene();


        // --------------------------------------------------------
        // Unbind Framebuffer
        // --------------------------------------------------------

        m_Framebuffer->Unbind();
    }


    // ============================================================
    // ImGui
    // ============================================================

    void EditorLayer::OnImGuiRender()
    {
        m_Dockspace.Begin();


        // --------------------------------------------------------
        // Main Menu Bar
        // --------------------------------------------------------

        if (ImGui::BeginMainMenuBar())
        {
            // ----------------------------------------------------
            // File
            // ----------------------------------------------------

            if (ImGui::BeginMenu("File"))
            {
                ImGui::MenuItem("New");
                ImGui::MenuItem("Open");
                ImGui::MenuItem("Save");

                ImGui::Separator();

                ImGui::MenuItem("Exit");

                ImGui::EndMenu();
            }


            // ----------------------------------------------------
            // Edit
            // ----------------------------------------------------

            if (ImGui::BeginMenu("Edit"))
            {
                ImGui::MenuItem("Undo");
                ImGui::MenuItem("Redo");

                ImGui::EndMenu();
            }


            // ----------------------------------------------------
            // View
            // ----------------------------------------------------

            if (ImGui::BeginMenu("View"))
            {
                ImGui::MenuItem("Viewport");
                ImGui::MenuItem("Hierarchy");
                ImGui::MenuItem("Inspector");
                ImGui::MenuItem("Console");

                ImGui::EndMenu();
            }


            // ----------------------------------------------------
            // Help
            // ----------------------------------------------------

            if (ImGui::BeginMenu("Help"))
            {
                ImGui::MenuItem("About");

                ImGui::EndMenu();
            }


            ImGui::EndMainMenuBar();
        }


        // --------------------------------------------------------
        // Panels
        // --------------------------------------------------------

        m_ViewportPanel.Render(
            *m_Framebuffer
        );

        m_HierarchyPanel.Render();

        m_InspectorPanel.Render();

        m_ConsolePanel.Render();


        // --------------------------------------------------------
        // End Dockspace
        // --------------------------------------------------------

        m_Dockspace.End();
    }
}