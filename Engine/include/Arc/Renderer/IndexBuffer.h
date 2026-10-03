#pragma once

namespace Arc
{
    class IndexBuffer
    {
    public:
        IndexBuffer(
            const unsigned int* indices,
            unsigned int count
        );

        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        unsigned int GetCount() const;
        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;
        unsigned int m_Count = 0;
    };
}