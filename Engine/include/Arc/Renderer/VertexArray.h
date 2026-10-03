#pragma once

#include <memory>

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
            const std::shared_ptr<VertexBuffer>& vertexBuffer
        );

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;
    };
}