#include "Core/Application.h"
#include "Core/Input.h"

#include "Arc/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

namespace Arc
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;

        // -----------------------------
        // GLFW Initialization
        // -----------------------------

        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW!\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(
            GLFW_OPENGL_PROFILE,
            GLFW_OPENGL_CORE_PROFILE
        );

        m_Window = glfwCreateWindow(
            1280,
            720,
            "Arc Engine",
            nullptr,
            nullptr
        );

        if (!m_Window)
        {
            std::cerr << "Failed to create GLFW window!\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);

        glfwSwapInterval(1);

        // -----------------------------
        // GLAD
        // -----------------------------

        if (!gladLoadGLLoader(
                (GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD!\n";

            glfwDestroyWindow(m_Window);
            m_Window = nullptr;

            glfwTerminate();

            return;
        }

        // -----------------------------
        // Input
        // -----------------------------

        Input::Init(m_Window);

        // -----------------------------
        // Renderer
        // -----------------------------

        Renderer::Init();

        // -----------------------------
        // ImGui
        // -----------------------------

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();

        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(
            m_Window,
            true
        );

        ImGui_ImplOpenGL3_Init("#version 460");

        // -----------------------------
        // Delta Time
        // -----------------------------

        m_LastFrameTime =
            static_cast<float>(glfwGetTime());
    }

    Application::~Application()
    {
        // -----------------------------
        // ImGui Shutdown
        // -----------------------------

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();

        ImGui::DestroyContext();

        // -----------------------------
        // Renderer Shutdown
        // -----------------------------

        Renderer::Shutdown();

        // -----------------------------
        // GLFW Shutdown
        // -----------------------------

        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            m_Window = nullptr;
        }

        glfwTerminate();

        s_Instance = nullptr;
    }

    void Application::Run()
    {
        if (!m_Window)
            return;

        while (!glfwWindowShouldClose(m_Window))
        {
            // -----------------------------
            // Delta Time
            // -----------------------------

            float currentTime =
                static_cast<float>(glfwGetTime());

            m_DeltaTime =
                currentTime - m_LastFrameTime;

            m_LastFrameTime = currentTime;

            // Prevent unusually large delta time
            // from causing huge movement.
            if (m_DeltaTime > 0.1f)
                m_DeltaTime = 0.1f;

            // -----------------------------
            // Events
            // -----------------------------

            glfwPollEvents();

            // -----------------------------
            // ImGui New Frame
            // -----------------------------

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();

            ImGui::NewFrame();

            // -----------------------------
            // Layer Update
            // -----------------------------

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            // -----------------------------
            // ImGui Layer Rendering
            // -----------------------------

            for (Layer* layer : m_LayerStack)
            {
                layer->OnImGuiRender();
            }

            // -----------------------------
            // ImGui Render
            // -----------------------------

            ImGui::Render();

            // -----------------------------
            // Render to Main Window
            // -----------------------------

            glBindFramebuffer(
                GL_FRAMEBUFFER,
                0
            );

            int displayWidth;
            int displayHeight;

            glfwGetFramebufferSize(
                m_Window,
                &displayWidth,
                &displayHeight
            );

            glViewport(
                0,
                0,
                displayWidth,
                displayHeight
            );

            ImGui_ImplOpenGL3_RenderDrawData(
                ImGui::GetDrawData()
            );

            // -----------------------------
            // Present Frame
            // -----------------------------

            glfwSwapBuffers(m_Window);
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    float Application::GetDeltaTime()
    {
        if (!s_Instance)
            return 0.0f;

        return s_Instance->m_DeltaTime;
    }
}