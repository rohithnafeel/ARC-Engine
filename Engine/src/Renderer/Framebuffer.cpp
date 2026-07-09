#include "Arc/Renderer/Framebuffer.h"

#include <glad/glad.h>
#include <iostream>

namespace Arc
{
    Framebuffer::Framebuffer(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height)
    {
        glGenFramebuffers(1, &m_FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

        std::cout << "Framebuffer ID: " << m_FBO << std::endl;
    }

        Framebuffer::~Framebuffer()
    {
        glDeleteFramebuffers(1, &m_FBO);
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
}