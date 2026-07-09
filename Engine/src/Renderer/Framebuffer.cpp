#include "Arc/Renderer/Framebuffer.h"


#include <glad/glad.h>
#include <iostream>

namespace Arc
{
    Framebuffer::Framebuffer(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height)
    {
        std::cout << "===== Framebuffer Constructor =====" << std::endl;

        glGenFramebuffers(1, &m_FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

        glGenTextures(1, &m_ColorAttachment);
        glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            m_Width,
            m_Height,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            nullptr
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glFramebufferTexture2D(
            GL_FRAMEBUFFER,
            GL_COLOR_ATTACHMENT0,
            GL_TEXTURE_2D,
            m_ColorAttachment,
            0
        );

        glGenRenderbuffers(1, &m_RBO);
        glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);

        glRenderbufferStorage(
            GL_RENDERBUFFER,
            GL_DEPTH24_STENCIL8,
            m_Width,
            m_Height
        );

        glFramebufferRenderbuffer(
            GL_FRAMEBUFFER,
            GL_DEPTH_STENCIL_ATTACHMENT,
            GL_RENDERBUFFER,
            m_RBO
        );

       GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

std::cout << "Framebuffer Status = " << status << std::endl;

if (status == GL_FRAMEBUFFER_COMPLETE)
{
    std::cout << "Framebuffer COMPLETE!" << std::endl;
}
else
{
    std::cout << "Framebuffer NOT COMPLETE!" << std::endl;
}
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        std::cout << "Framebuffer ID = " << m_FBO << std::endl;
    }

    Framebuffer::~Framebuffer()
    {
        glDeleteFramebuffers(1, &m_FBO);
        glDeleteTextures(1, &m_ColorAttachment);
        glDeleteRenderbuffers(1, &m_RBO);
    }

    void Framebuffer::Bind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
    }

    void Framebuffer::Unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    unsigned int Framebuffer::GetColorAttachment() const
    {
        return m_ColorAttachment;
    }
    unsigned int Framebuffer::GetWidth() const
{
    return m_Width;
}

unsigned int Framebuffer::GetHeight() const
{
    return m_Height;
}
}