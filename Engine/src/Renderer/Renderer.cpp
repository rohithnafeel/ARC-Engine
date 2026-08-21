#include "Arc/Renderer/Renderer.h"

#include <glad/glad.h>

namespace Arc
{
    static unsigned int s_VAO = 0;
    static unsigned int s_VBO = 0;
    static unsigned int s_ShaderProgram = 0;

    static const char* vertexShaderSource = R"(
        #version 460 core

        layout (location = 0) in vec2 aPos;

        void main()
        {
            gl_Position = vec4(aPos, 0.0, 1.0);
        }
    )";

    static const char* fragmentShaderSource = R"(
        #version 460 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0, 0.5, 0.2, 1.0);
        }
    )";

    void Renderer::Init()
    {
        glEnable(GL_DEPTH_TEST);

        float vertices[] =
        {
             0.0f,  0.5f,
            -0.5f, -0.5f,
             0.5f, -0.5f
        };

        glGenVertexArrays(1, &s_VAO);
        glGenBuffers(1, &s_VBO);

        glBindVertexArray(s_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, s_VBO);

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

        s_ShaderProgram = glCreateProgram();

        glAttachShader(
            s_ShaderProgram,
            vertexShader
        );

        glAttachShader(
            s_ShaderProgram,
            fragmentShader
        );

        glLinkProgram(s_ShaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glBindVertexArray(0);
    }

    void Renderer::Shutdown()
    {
        if (s_ShaderProgram)
            glDeleteProgram(s_ShaderProgram);

        if (s_VAO)
            glDeleteVertexArrays(1, &s_VAO);

        if (s_VBO)
            glDeleteBuffers(1, &s_VBO);

        s_ShaderProgram = 0;
        s_VAO = 0;
        s_VBO = 0;
    }

    void Renderer::BeginFrame()
    {
        glClearColor(
            0.1f,
            0.2f,
            0.3f,
            1.0f
        );

        glClear(
            GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT
        );
    }

    void Renderer::DrawTriangle()
    {
        glUseProgram(s_ShaderProgram);

        glBindVertexArray(s_VAO);

        glDrawArrays(
            GL_TRIANGLES,
            0,
            3
        );
    }

    void Renderer::EndFrame()
    {
        glBindVertexArray(0);
        glUseProgram(0);
    }
}