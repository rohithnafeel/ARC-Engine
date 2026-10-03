#include "Arc/Renderer/VertexBuffer.h"

#include <glad/glad.h>

namespace Arc
{
    VertexBuffer::VertexBuffer(
        const void* data,
        unsigned int size
    )
    {
        glGenBuffers(
            1,
            &m_RendererID
        );

        glBindBuffer(
            GL_ARRAY_BUFFER,
            m_RendererID
        );

        glBufferData(
            GL_ARRAY_BUFFER,
            size,
            data,
            GL_STATIC_DRAW
        );
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(
            1,
            &m_RendererID
        );
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(
            GL_ARRAY_BUFFER,
            m_RendererID
        );
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(
            GL_ARRAY_BUFFER,
            0
        );
    }

    void VertexBuffer::SetLayout(
        const BufferLayout& layout
    )
    {
        m_Layout = layout;
    }

    const BufferLayout&
    VertexBuffer::GetLayout() const
    {
        return m_Layout;
    }

    unsigned int VertexBuffer::GetRendererID() const
    {
        return m_RendererID;
    }
}