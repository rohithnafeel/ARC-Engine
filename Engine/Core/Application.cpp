#include "Core/Application.h"
#include "Core/Input.h"

#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/Renderer2D.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

namespace Arc
{
    Application* Application::s_Instance = nullptr;


    // ============================================================
    // Constructor
    // ============================================================

    Application::Application()
    {
        s_Instance = this;


        // --------------------------------------------------------
        // Initialize GLFW
        // --------------------------------------------------------

        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW!\n";
            return;
        }


        // --------------------------------------------------------
        // OpenGL Version
        // --------------------------------------------------------

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        glfwWindowHint(
            GLFW_OPENGL_PROFILE,
            GLFW_OPENGL_CORE_PROFILE
        );


        // --------------------------------------------------------
        // Create Window
        // --------------------------------------------------------

        m_Window =
            glfwCreateWindow(
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


        // --------------------------------------------------------
        // Make OpenGL Context Current
        // --------------------------------------------------------

        glfwMakeContextCurrent(m_Window);


        // Enable VSync
        glfwSwapInterval(1);


        // --------------------------------------------------------
        // Initialize GLAD
        // --------------------------------------------------------

        if (!gladLoadGLLoader(
                (GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD!\n";

            glfwDestroyWindow(m_Window);

            m_Window = nullptr;

            glfwTerminate();

            return;
        }


        // --------------------------------------------------------
        // Initialize Engine Systems
        // --------------------------------------------------------

        Input::Init(m_Window);

        Renderer::Init();

        Renderer2D::Init();


        // --------------------------------------------------------
        // Initialize ImGui
        // --------------------------------------------------------

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();

        io.ConfigFlags |=
            ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();


        ImGui_ImplGlfw_InitForOpenGL(
            m_Window,
            true
        );

        ImGui_ImplOpenGL3_Init(
            "#version 460"
        );


        // --------------------------------------------------------
        // Initialize Delta Time
        // --------------------------------------------------------

        m_LastFrameTime =
            static_cast<float>(
                glfwGetTime()
            );
    }


    // ============================================================
    // Destructor
    // ============================================================

    Application::~Application()
    {
        std::cout << "APPLICATION DESTRUCTOR\n";


        // --------------------------------------------------------
        // Shutdown ImGui
        // --------------------------------------------------------

        ImGui_ImplOpenGL3_Shutdown();

        ImGui_ImplGlfw_Shutdown();

        ImGui::DestroyContext();


        // --------------------------------------------------------
        // Shutdown Renderer Systems
        // --------------------------------------------------------

        Renderer2D::Shutdown();

        Renderer::Shutdown();


        // --------------------------------------------------------
        // Destroy Window
        // --------------------------------------------------------

        if (m_Window)
        {
            glfwDestroyWindow(m_Window);

            m_Window = nullptr;
        }


        // --------------------------------------------------------
        // Shutdown GLFW
        // --------------------------------------------------------

        glfwTerminate();

        s_Instance = nullptr;
    }


    // ============================================================
    // Run
    // ============================================================

    void Application::Run()
    {
        std::cout << "APPLICATION RUN STARTED\n";


        if (!m_Window)
        {
            std::cout << "NO WINDOW - RUN EXITING\n";
            return;
        }


        while (!glfwWindowShouldClose(m_Window))
        {
            // ----------------------------------------------------
            // Calculate Delta Time
            // ----------------------------------------------------

            float currentTime =
                static_cast<float>(
                    glfwGetTime()
                );

            m_DeltaTime =
                currentTime -
                m_LastFrameTime;

            m_LastFrameTime =
                currentTime;


            // ----------------------------------------------------
            // Prevent Extremely Large Delta Time
            // ----------------------------------------------------

            if (m_DeltaTime > 0.1f)
                m_DeltaTime = 0.1f;


            // ----------------------------------------------------
            // Poll Events
            // ----------------------------------------------------

            glfwPollEvents();


            // ----------------------------------------------------
            // DEBUG:
            // Check Window Close Flag
            // ----------------------------------------------------

            if (glfwWindowShouldClose(m_Window))
            {
                std::cout
                    << "CLOSE FLAG SET AFTER POLL EVENTS\n";
            }


            // ----------------------------------------------------
            // Start ImGui Frame
            // ----------------------------------------------------

            ImGui_ImplOpenGL3_NewFrame();

            ImGui_ImplGlfw_NewFrame();

            ImGui::NewFrame();


            // ----------------------------------------------------
            // Update Layers
            // ----------------------------------------------------

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate();
            }


            // ----------------------------------------------------
            // Render ImGui
            // ----------------------------------------------------

            for (Layer* layer : m_LayerStack)
            {
                layer->OnImGuiRender();
            }


            // ----------------------------------------------------
            // Finish ImGui Frame
            // ----------------------------------------------------

            ImGui::Render();


            // ----------------------------------------------------
            // Bind Default Framebuffer
            // ----------------------------------------------------

            glBindFramebuffer(
                GL_FRAMEBUFFER,
                0
            );


            // ----------------------------------------------------
            // Set Viewport to Window Size
            // ----------------------------------------------------

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


            // ----------------------------------------------------
            // Render ImGui
            // ----------------------------------------------------

            ImGui_ImplOpenGL3_RenderDrawData(
                ImGui::GetDrawData()
            );


            // ----------------------------------------------------
            // Swap Buffers
            // ----------------------------------------------------

            glfwSwapBuffers(m_Window);
        }


        // --------------------------------------------------------
        // DEBUG:
        // Main Application Loop Ended
        // --------------------------------------------------------

        std::cout
            << "APPLICATION RUN LOOP ENDED\n";
    }


    // ============================================================
    // Push Layer
    // ============================================================

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }


    // ============================================================
    // Push Overlay
    // ============================================================

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }


    // ============================================================
    // Get Delta Time
    // ============================================================

    float Application::GetDeltaTime()
    {
        if (!s_Instance)
            return 0.0f;

        return s_Instance->m_DeltaTime;
    }
}