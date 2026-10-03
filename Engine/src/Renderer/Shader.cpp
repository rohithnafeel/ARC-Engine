#include "Arc/Renderer/Shader.h"

#include <glad/glad.h>

namespace Arc
{
    Shader::Shader(
        const std::string& vertexSource,
        const std::string& fragmentSource
    )
    {
        // -----------------------------
        // Vertex Shader
        // -----------------------------

        unsigned int vertexShader =
            glCreateShader(GL_VERTEX_SHADER);

        const char* vertexSourceCStr =
            vertexSource.c_str();

        glShaderSource(
            vertexShader,
            1,
            &vertexSourceCStr,
            nullptr
        );

        glCompileShader(vertexShader);

        // -----------------------------
        // Fragment Shader
        // -----------------------------

        unsigned int fragmentShader =
            glCreateShader(GL_FRAGMENT_SHADER);

        const char* fragmentSourceCStr =
            fragmentSource.c_str();

        glShaderSource(
            fragmentShader,
            1,
            &fragmentSourceCStr,
            nullptr
        );

        glCompileShader(fragmentShader);

        // -----------------------------
        // Shader Program
        // -----------------------------

        m_RendererID =
            glCreateProgram();

        glAttachShader(
            m_RendererID,
            vertexShader
        );

        glAttachShader(
            m_RendererID,
            fragmentShader
        );

        glLinkProgram(
            m_RendererID
        );

        // -----------------------------
        // Cleanup
        // -----------------------------

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader()
    {
        if (m_RendererID)
        {
            glDeleteProgram(
                m_RendererID
            );
        }
    }

    void Shader::Bind() const
    {
        glUseProgram(
            m_RendererID
        );
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::SetMat4(
        const std::string& name,
        const glm::mat4& value
    )
    {
        int location =
            GetUniformLocation(name);

        glUniformMatrix4fv(
            location,
            1,
            GL_FALSE,
            &value[0][0]
        );
    }

    unsigned int Shader::GetRendererID() const
    {
        return m_RendererID;
    }

    int Shader::GetUniformLocation(
        const std::string& name
    ) const
    {
        return glGetUniformLocation(
            m_RendererID,
            name.c_str()
        );
    }
}