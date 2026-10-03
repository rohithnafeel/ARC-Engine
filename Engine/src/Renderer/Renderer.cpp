#include "Arc/Renderer/Renderer.h"
#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/VertexBuffer.h"
#include "Arc/Renderer/Shader.h"
#include "Arc/Renderer/Buffer.h"

#include <glad/glad.h>

#include <glm/glm.hpp>

#include <memory>

namespace Arc
{
    static std::unique_ptr<VertexArray> s_VertexArray;
    static std::shared_ptr<VertexBuffer> s_VertexBuffer;
    static std::unique_ptr<Shader> s_Shader;

    static const char* vertexShaderSource = R"(
        #version 460 core

        layout (location = 0) in vec2 aPos;

        uniform mat4 u_ViewProjection;

        void main()
        {
            gl_Position =
                u_ViewProjection *
                vec4(aPos, 0.0, 1.0);
        }
    )";

    static const char* fragmentShaderSource = R"(
        #version 460 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(
                1.0,
                0.5,
                0.2,
                1.0
            );
        }
    )";

    void Renderer::Init()
    {
        // -----------------------------
        // Vertex Array
        // -----------------------------

        s_VertexArray =
            std::make_unique<VertexArray>();

        // -----------------------------
        // Vertex Data
        // -----------------------------

        float vertices[] =
        {
             0.0f,  0.5f,
            -0.5f, -0.5f,
             0.5f, -0.5f
        };

        // -----------------------------
        // Vertex Buffer
        // -----------------------------

        s_VertexBuffer =
            std::make_shared<VertexBuffer>(
                vertices,
                sizeof(vertices)
            );

        // -----------------------------
        // Vertex Layout
        // -----------------------------

        BufferLayout layout =
        {
            {
                ShaderDataType::Float2,
                "a_Position"
            }
        };

        s_VertexBuffer->SetLayout(layout);

        // -----------------------------
        // Add Buffer To Vertex Array
        // -----------------------------

        s_VertexArray->AddVertexBuffer(
            s_VertexBuffer
        );

        s_VertexArray->Unbind();

        // -----------------------------
        // Shader
        // -----------------------------

        s_Shader =
            std::make_unique<Shader>(
                vertexShaderSource,
                fragmentShaderSource
            );
    }

    void Renderer::SetCamera(
        const glm::mat4& viewProjection
    )
    {
        s_Shader->Bind();

        s_Shader->SetMat4(
            "u_ViewProjection",
            viewProjection
        );
    }

    void Renderer::Shutdown()
    {
        s_Shader.reset();

        s_VertexBuffer.reset();

        s_VertexArray.reset();
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
        s_Shader->Bind();

        s_VertexArray->Bind();

        glDrawArrays(
            GL_TRIANGLES,
            0,
            3
        );
    }

    void Renderer::EndFrame()
    {
        s_VertexArray->Unbind();

        s_Shader->Unbind();
    }
}