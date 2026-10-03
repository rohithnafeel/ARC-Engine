#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/VertexBuffer.h"
#include "Arc/Renderer/IndexBuffer.h"
#include "Arc/Renderer/Buffer.h"

#include <glad/glad.h>

#include <cstdint>
namespace Arc
{
    static GLenum ShaderDataTypeToOpenGLBaseType(
        ShaderDataType type
    )
    {
        switch (type)
        {
            case ShaderDataType::Float:
            case ShaderDataType::Float2:
            case ShaderDataType::Float3:
            case ShaderDataType::Float4:
            case ShaderDataType::Mat3:
            case ShaderDataType::Mat4:
                return GL_FLOAT;

            case ShaderDataType::Int:
            case ShaderDataType::Int2:
            case ShaderDataType::Int3:
            case ShaderDataType::Int4:
                return GL_INT;

            case ShaderDataType::Bool:
                return GL_BOOL;

            case ShaderDataType::None:
                break;
        }

        return GL_NONE;
    }

    VertexArray::VertexArray()
    {
        glGenVertexArrays(
            1,
            &m_RendererID
        );
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(
            1,
            &m_RendererID
        );
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(
            m_RendererID
        );
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddVertexBuffer(
        const std::shared_ptr<VertexBuffer>& vertexBuffer
    )
    {
        Bind();

        vertexBuffer->Bind();

        const auto& layout =
            vertexBuffer->GetLayout();

        unsigned int index = 0;

        for (const auto& element : layout)
        {
            GLenum type =
                ShaderDataTypeToOpenGLBaseType(
                    element.Type
                );

            glEnableVertexAttribArray(index);

            glVertexAttribPointer(
                index,
                element.GetComponentCount(),
                type,
                element.Normalized
                    ? GL_TRUE
                    : GL_FALSE,
                layout.GetStride(),
                (const void*)(uintptr_t)element.Offset
            );

            index++;
        }
    }

    void VertexArray::SetIndexBuffer(
        const std::shared_ptr<IndexBuffer>& indexBuffer
    )
    {
        Bind();

        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }

    const std::shared_ptr<IndexBuffer>&
    VertexArray::GetIndexBuffer() const
    {
        return m_IndexBuffer;
    }

    unsigned int VertexArray::GetRendererID() const
    {
        return m_RendererID;
    }
}