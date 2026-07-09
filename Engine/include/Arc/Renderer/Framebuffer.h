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

unsigned int GetWidth() const;
unsigned int GetHeight() const;

        unsigned int GetColorAttachment() const;

    private:
        unsigned int m_FBO = 0;
        unsigned int m_ColorAttachment = 0;
        unsigned int m_RBO = 0;

        unsigned int m_Width;
        unsigned int m_Height;
    };
}