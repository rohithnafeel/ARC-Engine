#include "Arc/Renderer/Texture2D.h"

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>

namespace Arc
{
    Texture2D::Texture2D(
        const std::string& path
    )
    {
        stbi_set_flip_vertically_on_load(1);

        unsigned char* data =
            stbi_load(
                path.c_str(),
                &m_Width,
                &m_Height,
                &m_Channels,
                0
            );

        if (!data)
        {
            std::cerr
                << "Failed to load texture: "
                << path
                << '\n';

            return;
        }

        GLenum internalFormat = 0;
        GLenum dataFormat = 0;

        if (m_Channels == 4)
        {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        }
        else if (m_Channels == 3)
        {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        else
        {
            std::cerr
                << "Unsupported texture format: "
                << path
                << '\n';

            stbi_image_free(data);
            return;
        }

        glGenTextures(
            1,
            &m_RendererID
        );

        glBindTexture(
            GL_TEXTURE_2D,
            m_RendererID
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MIN_FILTER,
            GL_LINEAR_MIPMAP_LINEAR
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MAG_FILTER,
            GL_NEAREST
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

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            internalFormat,
            m_Width,
            m_Height,
            0,
            dataFormat,
            GL_UNSIGNED_BYTE,
            data
        );

        glGenerateMipmap(
            GL_TEXTURE_2D
        );

        stbi_image_free(data);

        glBindTexture(
            GL_TEXTURE_2D,
            0
        );

        std::cout
            << "Loaded texture: "
            << path
            << " ("
            << m_Width
            << "x"
            << m_Height
            << ")\n";
    }

    Texture2D::~Texture2D()
    {
        if (m_RendererID != 0)
        {
            glDeleteTextures(
                1,
                &m_RendererID
            );
        }
    }

    void Texture2D::Bind(
        unsigned int slot
    ) const
    {
        glActiveTexture(
            GL_TEXTURE0 + slot
        );

        glBindTexture(
            GL_TEXTURE_2D,
            m_RendererID
        );
    }

    void Texture2D::Unbind() const
    {
        glBindTexture(
            GL_TEXTURE_2D,
            0
        );
    }

    unsigned int Texture2D::GetRendererID() const
    {
        return m_RendererID;
    }

    int Texture2D::GetWidth() const
    {
        return m_Width;
    }

    int Texture2D::GetHeight() const
    {
        return m_Height;
    }
}