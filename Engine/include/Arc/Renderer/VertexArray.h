#pragma once

#include <memory>

namespace Arc
{
    class VertexBuffer;
    class IndexBuffer;

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(
            const std::shared_ptr<VertexBuffer>& vertexBuffer
        );

        void SetIndexBuffer(
            const std::shared_ptr<IndexBuffer>& indexBuffer
        );

        const std::shared_ptr<IndexBuffer>&
        GetIndexBuffer() const;

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;

        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };
}