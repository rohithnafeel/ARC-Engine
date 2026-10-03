#include "Arc/Renderer/VertexArray.h"
#include "Arc/Renderer/VertexBuffer.h"

#include <glad/glad.h>

namespace Arc
{
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
        const VertexBuffer& vertexBuffer
    )
    {
        Bind();

        vertexBuffer.Bind();

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            2 * sizeof(float),
            (void*)0
        );
    }

    unsigned int VertexArray::GetRendererID() const
    {
        return m_RendererID;
    }
}