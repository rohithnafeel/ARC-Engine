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
    static std::unique_ptr<VertexArray> s_VertexArray;
    static std::shared_ptr<VertexBuffer> s_VertexBuffer;
    static std::shared_ptr<IndexBuffer> s_IndexBuffer;
    static std::unique_ptr<Shader> s_Shader;

    static const char* vertexShaderSource = R"(
        #version 460 core

        layout (location = 0) in vec3 a_Position;
        layout (location = 1) in vec2 a_TexCoord;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        out vec2 v_TexCoord;

        void main()
        {
            gl_Position =
                u_ViewProjection *
                u_Transform *
                vec4(a_Position, 1.0);

            v_TexCoord = a_TexCoord;
        }
    )";

    static const char* fragmentShaderSource = R"(
        #version 460 core

        in vec2 v_TexCoord;

        uniform sampler2D u_Texture;
uniform vec4 u_Tint;

out vec4 FragColor;

void main()
{
    FragColor =
        texture(
            u_Texture,
            v_TexCoord
        ) * u_Tint;
}
    )";

    void Renderer2D::Init()
    {
        s_VertexArray =
            std::make_unique<VertexArray>();

        float vertices[] =
        {
            // Position              // UV
            -0.5f, -0.5f, 0.0f,      0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,      1.0f, 0.0f,
             0.5f,  0.5f, 0.0f,      1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f,      0.0f, 1.0f
        };

        s_VertexBuffer =
            std::make_shared<VertexBuffer>(
                vertices,
                sizeof(vertices)
            );

        BufferLayout layout =
        {
            {
                ShaderDataType::Float3,
                "a_Position"
            },
            {
                ShaderDataType::Float2,
                "a_TexCoord"
            }
        };

        s_VertexBuffer->SetLayout(
            layout
        );

        s_VertexArray->AddVertexBuffer(
            s_VertexBuffer
        );

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

        s_VertexArray->SetIndexBuffer(
            s_IndexBuffer
        );

        s_VertexArray->Unbind();

        s_Shader =
            std::make_unique<Shader>(
                vertexShaderSource,
                fragmentShaderSource
            );
    }

    void Renderer2D::Shutdown()
    {
        s_Shader.reset();
        s_IndexBuffer.reset();
        s_VertexBuffer.reset();
        s_VertexArray.reset();
    }

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

    void Renderer2D::DrawQuad(
    const Transform& transform,
    const Texture2D& texture,
    const glm::vec4& tint
)
    {
        s_Shader->SetMat4(
            "u_Transform",
            transform.GetTransform()
        );
        

        texture.Bind(0);

        s_Shader->SetInt(
            "u_Texture",
            0
        );

        s_VertexArray->Bind();

        glDrawElements(
            GL_TRIANGLES,
            s_IndexBuffer->GetCount(),
            GL_UNSIGNED_INT,
            nullptr
        );
    }

    void Renderer2D::EndScene()
    {
        s_VertexArray->Unbind();
        s_Shader->Unbind();
    }
}