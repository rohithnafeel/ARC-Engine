#include "Arc/Renderer/Renderer2D.h"

#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/VertexBuffer.h"
#include "Arc/Renderer/IndexBuffer.h"
#include "Arc/Renderer/Shader.h"
#include "Arc/Renderer/Buffer.h"

#include <glad/glad.h>

#include <memory>

namespace Arc
{
    // ============================================================
    // Renderer2D Resources
    // ============================================================

    static std::unique_ptr<VertexArray> s_VertexArray;
    static std::shared_ptr<VertexBuffer> s_VertexBuffer;
    static std::shared_ptr<IndexBuffer> s_IndexBuffer;
    static std::unique_ptr<Shader> s_Shader;


    // ============================================================
    // Vertex Shader
    // ============================================================

    static const char* vertexShaderSource = R"(
        #version 460 core

        layout (location = 0) in vec3 a_Position;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        void main()
        {
            gl_Position =
                u_ViewProjection *
                u_Transform *
                vec4(a_Position, 1.0);
        }
    )";


    // ============================================================
    // Fragment Shader
    // ============================================================

    static const char* fragmentShaderSource = R"(
        #version 460 core

        uniform vec4 u_Color;

        out vec4 FragColor;

        void main()
        {
            FragColor = u_Color;
        }
    )";


    // ============================================================
    // Init
    // ============================================================

    void Renderer2D::Init()
    {
        // --------------------------------------------------------
        // Vertex Array
        // --------------------------------------------------------

        s_VertexArray =
            std::make_unique<VertexArray>();


        // --------------------------------------------------------
        // Unit Quad
        // --------------------------------------------------------

        float vertices[] =
        {
            -0.5f, -0.5f, 0.0f,  // 0
             0.5f, -0.5f, 0.0f,  // 1
             0.5f,  0.5f, 0.0f,  // 2
            -0.5f,  0.5f, 0.0f   // 3
        };


        // --------------------------------------------------------
        // Vertex Buffer
        // --------------------------------------------------------

        s_VertexBuffer =
            std::make_shared<VertexBuffer>(
                vertices,
                sizeof(vertices)
            );


        // --------------------------------------------------------
        // Vertex Layout
        // --------------------------------------------------------

        BufferLayout layout =
        {
            {
                ShaderDataType::Float3,
                "a_Position"
            }
        };


        s_VertexBuffer->SetLayout(layout);


        // --------------------------------------------------------
        // Attach Vertex Buffer
        // --------------------------------------------------------

        s_VertexArray->AddVertexBuffer(
            s_VertexBuffer
        );


        // --------------------------------------------------------
        // Index Buffer
        // --------------------------------------------------------

        unsigned int indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };


        s_IndexBuffer =
            std::make_shared<IndexBuffer>(
                indices,
                6
            );


        // --------------------------------------------------------
        // Attach Index Buffer
        // --------------------------------------------------------

        s_VertexArray->SetIndexBuffer(
            s_IndexBuffer
        );


        // --------------------------------------------------------
        // Unbind
        // --------------------------------------------------------

        s_VertexArray->Unbind();


        // --------------------------------------------------------
        // Shader
        // --------------------------------------------------------

        s_Shader =
            std::make_unique<Shader>(
                vertexShaderSource,
                fragmentShaderSource
            );
    }


    // ============================================================
    // Shutdown
    // ============================================================

    void Renderer2D::Shutdown()
    {
        s_Shader.reset();

        s_IndexBuffer.reset();

        s_VertexBuffer.reset();

        s_VertexArray.reset();
    }


    // ============================================================
    // Begin Scene
    // ============================================================

    void Renderer2D::BeginScene(
        const glm::mat4& viewProjection
    )
    {
        s_Shader->Bind();

        s_Shader->SetMat4(
            "u_ViewProjection",
            viewProjection
        );
    }


    // ============================================================
    // Draw Quad
    // ============================================================

    void Renderer2D::DrawQuad(
        const Transform& transform,
        const glm::vec4& color
    )
    {
        // --------------------------------------------------------
        // Upload Transform
        // --------------------------------------------------------

        s_Shader->SetMat4(
            "u_Transform",
            transform.GetTransform()
        );


        // --------------------------------------------------------
        // Upload Color
        // --------------------------------------------------------

        int colorLocation =
            glGetUniformLocation(
                s_Shader->GetRendererID(),
                "u_Color"
            );


        glUniform4f(
            colorLocation,
            color.r,
            color.g,
            color.b,
            color.a
        );


        // --------------------------------------------------------
        // Bind Vertex Array
        // --------------------------------------------------------

        s_VertexArray->Bind();


        // --------------------------------------------------------
        // Indexed Draw
        // --------------------------------------------------------

        glDrawElements(
            GL_TRIANGLES,
            s_IndexBuffer->GetCount(),
            GL_UNSIGNED_INT,
            nullptr
        );
    }


    // ============================================================
    // End Scene
    // ============================================================

    void Renderer2D::EndScene()
    {
        s_VertexArray->Unbind();

        s_Shader->Unbind();
    }
}