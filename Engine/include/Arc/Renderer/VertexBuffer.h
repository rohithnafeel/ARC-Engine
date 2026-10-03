#pragma once

namespace Arc
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;
    };
}