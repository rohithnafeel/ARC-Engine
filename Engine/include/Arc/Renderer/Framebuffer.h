#pragma once

namespace Arc
{
    class Framebuffer
    {
    public:
        Framebuffer(unsigned int width, unsigned int height);
        ~Framebuffer();

        void Bind();
        void Unbind();

        void Resize(unsigned int width, unsigned int height);

        unsigned int GetColorAttachment() const;

        unsigned int GetWidth() const;
        unsigned int GetHeight() const;

    private:
        unsigned int m_RendererID = 0;
        unsigned int m_ColorAttachment = 0;
        unsigned int m_DepthAttachment = 0;

        unsigned int m_Width = 0;
        unsigned int m_Height = 0;
    };
}