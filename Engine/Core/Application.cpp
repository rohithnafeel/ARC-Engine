#include "Core/Application.h"
#include "Arc/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

namespace Arc
{
    Application::Application()
    {
        // -------------------------
        // Initialize GLFW
        // -------------------------

        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // -------------------------
        // Create Window
        // -------------------------

        m_Window = glfwCreateWindow(
            1280,
            720,
            "Arc Engine",
            nullptr,
            nullptr
        );

        if (!m_Window)
        {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        // -------------------------
        // Initialize GLAD
        // -------------------------

        if (!gladLoadGLLoader(
                (GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD\n";

            glfwDestroyWindow(m_Window);
            m_Window = nullptr;

            glfwTerminate();
            return;
        }

        // -------------------------
        // Initialize Renderer
        // -------------------------

        Renderer::Init();

        // -------------------------
        // Initialize ImGui
        // -------------------------

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();

io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(
            m_Window,
            true
        );

        ImGui_ImplOpenGL3_Init(
            "#version 460"
        );
    }

    Application::~Application()
    {
        // -------------------------
        // Shutdown ImGui
        // -------------------------

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();

        ImGui::DestroyContext();

        // -------------------------
        // Shutdown Renderer
        // -------------------------

        Renderer::Shutdown();

        // -------------------------
        // Destroy Window
        // -------------------------

        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
        }

        glfwTerminate();
    }

    void Application::Run()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();

        // -------------------------
        // ImGui: Start frame
        // -------------------------

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // -------------------------
        // Engine layers
        // -------------------------

        for (Layer* layer : m_LayerStack)
        {
            layer->OnUpdate();
        }

        // -------------------------
        // Editor UI
        // -------------------------

        for (Layer* layer : m_LayerStack)
        {
            layer->OnImGuiRender();
        }

        // -------------------------
        // ImGui: Render
        // -------------------------

        ImGui::Render();

        // Make absolutely sure
        // we're rendering ImGui to
        // the main window.
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

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
}