#pragma once

#include "Arc/Renderer/Buffer.h"

namespace Arc
{
    class VertexBuffer
    {
    public:
        VertexBuffer(
            const void* data,
            unsigned int size
        );

        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

        void SetLayout(const BufferLayout& layout);
        const BufferLayout& GetLayout() const;

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;

        BufferLayout m_Layout;
    };
}