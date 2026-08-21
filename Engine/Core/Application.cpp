#include "Core/Application.h"
#include "Arc/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Arc
{
    const char* vertexShaderSource = R"(
        #version 460 core

        layout (location = 0) in vec2 aPos;

        void main()
        {
            gl_Position = vec4(aPos, 0.0, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 460 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0, 0.5, 0.2, 1.0);
        }
    )";

    Application::Application()
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

        if (!gladLoadGLLoader(
                (GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD\n";

            glfwDestroyWindow(m_Window);
            m_Window = nullptr;

            glfwTerminate();
            return;
        }

        Renderer::Init();

        glEnable(GL_DEPTH_TEST);

        float vertices[] =
        {
             0.0f,  0.5f,
            -0.5f, -0.5f,
             0.5f, -0.5f
        };

        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(1, &m_VBO);

        glBindVertexArray(m_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(vertices),
            vertices,
            GL_STATIC_DRAW
        );

        glVertexAttribPointer(
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            2 * sizeof(float),
            (void*)0
        );

        glEnableVertexAttribArray(0);

        unsigned int vertexShader =
            glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(
            vertexShader,
            1,
            &vertexShaderSource,
            nullptr
        );

        glCompileShader(vertexShader);

        unsigned int fragmentShader =
            glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(
            fragmentShader,
            1,
            &fragmentShaderSource,
            nullptr
        );

        glCompileShader(fragmentShader);

        m_ShaderProgram = glCreateProgram();

        glAttachShader(
            m_ShaderProgram,
            vertexShader
        );

        glAttachShader(
            m_ShaderProgram,
            fragmentShader
        );

        glLinkProgram(m_ShaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glBindVertexArray(0);
    }

    Application::~Application()
{
    Renderer::Shutdown();

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

        for (Layer* layer : m_LayerStack)
        {
            layer->OnUpdate();
        }

        Renderer::BeginFrame();

        Renderer::DrawTriangle();

        Renderer::EndFrame();

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