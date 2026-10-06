#include "Arc/Editor/EditorLayer.h"

#include "Core/Application.h"
#include "Core/Input.h"

#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Renderer2D.h"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <memory>

namespace Arc
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer"),
          m_Camera(
              -8.0f,
               8.0f,
              -4.5f,
               4.5f
          )
    {
    }

    void EditorLayer::OnAttach()
    {
        // --------------------------------------------------
        // Framebuffer
        // --------------------------------------------------

        m_Framebuffer =
            std::make_unique<Framebuffer>(
                1280,
                720
            );


        // --------------------------------------------------
        // Scene
        // --------------------------------------------------

        m_Scene =
            std::make_unique<Scene>();


        // --------------------------------------------------
        // Player
        // --------------------------------------------------

        Entity& player =
            m_Scene->CreateEntity(
                "Player"
            );

        player.GetTransform().Position =
        {
            0.0f,
            0.0f,
            0.0f
        };

        player.GetTransform().Scale =
        {
            2.0f,
            2.0f,
            1.0f
        };


        // --------------------------------------------------
        // Player Sprite
        // --------------------------------------------------

        player.GetSpriteRenderer().Texture =
            std::make_shared<Texture2D>(
                "../Assets/player.jpg"
            );


        // --------------------------------------------------
        // Enemy
        // --------------------------------------------------

        Entity& enemy =
            m_Scene->CreateEntity(
                "Enemy"
            );

        enemy.GetTransform().Position =
        {
            3.0f,
            1.0f,
            0.0f
        };


        // --------------------------------------------------
        // Ground
        // --------------------------------------------------

        Entity& ground =
            m_Scene->CreateEntity(
                "Ground"
            );

        ground.GetTransform().Position =
        {
            0.0f,
            -3.0f,
            0.0f
        };

        ground.GetTransform().Scale =
        {
            6.0f,
            1.0f,
            1.0f
        };
    }


    void EditorLayer::OnDetach()
    {
        m_Scene.reset();

        m_Framebuffer.reset();
    }


    void EditorLayer::OnUpdate()
    {
        // --------------------------------------------------
        // Camera Movement
        // --------------------------------------------------

        float speed = 5.0f;

        float deltaTime =
            Application::GetDeltaTime();

        glm::vec3 cameraPosition =
            m_Camera.GetPosition();


        if (Input::IsKeyPressed(
                GLFW_KEY_W))
        {
            cameraPosition.y +=
                speed * deltaTime;
        }


        if (Input::IsKeyPressed(
                GLFW_KEY_S))
        {
            cameraPosition.y -=
                speed * deltaTime;
        }


        if (Input::IsKeyPressed(
                GLFW_KEY_A))
        {
            cameraPosition.x -=
                speed * deltaTime;
        }


        if (Input::IsKeyPressed(
                GLFW_KEY_D))
        {
            cameraPosition.x +=
                speed * deltaTime;
        }


        m_Camera.SetPosition(
            cameraPosition
        );


        // --------------------------------------------------
        // Begin Framebuffer
        // --------------------------------------------------

        m_Framebuffer->Bind();


        // --------------------------------------------------
        // Begin Rendering
        // --------------------------------------------------

        Renderer::BeginFrame();


        // --------------------------------------------------
        // Begin 2D Scene
        // --------------------------------------------------

        Renderer2D::BeginScene(
            m_Camera.GetViewProjectionMatrix()
        );


        // --------------------------------------------------
        // Render Entities
        // --------------------------------------------------

        for (
            auto& entity :
            m_Scene->GetEntities()
        )
        {
            SpriteRenderer& sprite =
                entity->GetSpriteRenderer();

            if (sprite.Texture)
            {
                Renderer2D::DrawQuad(
    entity->GetTransform(),
    *sprite.Texture,
    sprite.Tint
);
            }
        }


        // --------------------------------------------------
        // End 2D Scene
        // --------------------------------------------------

        Renderer2D::EndScene();


        // --------------------------------------------------
        // End Framebuffer
        // --------------------------------------------------

        m_Framebuffer->Unbind();
    }


    void EditorLayer::OnImGuiRender()
    {
        // --------------------------------------------------
        // Begin Dockspace
        // --------------------------------------------------

        m_Dockspace.Begin();


        // --------------------------------------------------
        // Viewport
        // --------------------------------------------------

        m_ViewportPanel.Render(
            *m_Framebuffer
        );


        // --------------------------------------------------
        // Hierarchy
        // --------------------------------------------------

        m_HierarchyPanel.Render(
            *m_Scene
        );


        // --------------------------------------------------
        // Inspector
        // --------------------------------------------------

        m_InspectorPanel.Render(
            m_HierarchyPanel.GetSelectedEntity()
        );


        // --------------------------------------------------
        // Console
        // --------------------------------------------------

        m_ConsolePanel.Render();


        // --------------------------------------------------
        // End Dockspace
        // --------------------------------------------------

        m_Dockspace.End();
    }
}