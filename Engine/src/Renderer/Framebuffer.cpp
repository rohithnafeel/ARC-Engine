#include "Arc/Renderer/Framebuffer.h"

#include <glad/glad.h>

#include <iostream>

namespace Arc
{
    Framebuffer::Framebuffer(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height)
    {
        glGenFramebuffers(1, &m_RendererID);
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

        // Color attachment
        glGenTextures(1, &m_ColorAttachment);
        glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA8,
            m_Width,
            m_Height,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            nullptr
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MIN_FILTER,
            GL_LINEAR
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MAG_FILTER,
            GL_LINEAR
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_WRAP_S,
            GL_CLAMP_TO_EDGE
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_WRAP_T,
            GL_CLAMP_TO_EDGE
        );

        glFramebufferTexture2D(
            GL_FRAMEBUFFER,
            GL_COLOR_ATTACHMENT0,
            GL_TEXTURE_2D,
            m_ColorAttachment,
            0
        );

        // Depth attachment
        glGenRenderbuffers(1, &m_DepthAttachment);
        glBindRenderbuffer(GL_RENDERBUFFER, m_DepthAttachment);

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
            m_DepthAttachment
        );

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        {
            std::cerr << "Framebuffer is incomplete!\n";
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    Framebuffer::~Framebuffer()
    {
        glDeleteFramebuffers(1, &m_RendererID);
        glDeleteTextures(1, &m_ColorAttachment);
        glDeleteRenderbuffers(1, &m_DepthAttachment);
    }

    void Framebuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

    glViewport(
        0,
        0,
        m_Width,
        m_Height
    );

    glClearColor(
        1.0f,
        0.0f,
        0.0f,
        1.0f
    );

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );
}
    void Framebuffer::Unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Framebuffer::Resize(
    unsigned int width,
    unsigned int height
)
{
    if (width == 0 || height == 0)
        return;

    if (width == m_Width && height == m_Height)
        return;

    m_Width = width;
    m_Height = height;

    glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

    // Resize color texture
    glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        m_Width,
        m_Height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        nullptr
    );

    // Resize depth/stencil buffer
    glBindRenderbuffer(GL_RENDERBUFFER, m_DepthAttachment);

    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_DEPTH24_STENCIL8,
        m_Width,
        m_Height
    );

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
{
    std::cerr << "Framebuffer is incomplete! Status: "
              << glCheckFramebufferStatus(GL_FRAMEBUFFER)
              << "\n";
}
else
{
    std::cout << "Framebuffer is COMPLETE\n";
}

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