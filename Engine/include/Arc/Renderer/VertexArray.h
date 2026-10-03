#pragma once

namespace Arc
{
    class VertexBuffer;

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(
            const VertexBuffer& vertexBuffer
        );

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;
    };
}