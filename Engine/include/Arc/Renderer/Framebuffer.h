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

        unsigned int GetColorAttachment() const;

    private:
        unsigned int m_FBO = 0;
        unsigned int m_ColorAttachment = 0;
        unsigned int m_RBO = 0;

        unsigned int m_Width;
        unsigned int m_Height;
    };
}