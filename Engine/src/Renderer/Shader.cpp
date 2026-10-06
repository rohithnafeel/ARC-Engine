#include "Arc/Renderer/Shader.h"

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace Arc
{
    static void CheckShaderCompile(
        unsigned int shader,
        const char* type
    )
    {
        int success = 0;

        glGetShaderiv(
            shader,
            GL_COMPILE_STATUS,
            &success
        );

        if (!success)
        {
            char infoLog[1024];

            glGetShaderInfoLog(
                shader,
                1024,
                nullptr,
                infoLog
            );

            std::cerr
                << "Shader compilation failed ("
                << type
                << "):\n"
                << infoLog
                << '\n';
        }
    }

    static void CheckProgramLink(
        unsigned int program
    )
    {
        int success = 0;

        glGetProgramiv(
            program,
            GL_LINK_STATUS,
            &success
        );

        if (!success)
        {
            char infoLog[1024];

            glGetProgramInfoLog(
                program,
                1024,
                nullptr,
                infoLog
            );

            std::cerr
                << "Shader program linking failed:\n"
                << infoLog
                << '\n';
        }
    }

    Shader::Shader(
        const char* vertexSource,
        const char* fragmentSource
    )
    {
        unsigned int vertexShader =
            glCreateShader(
                GL_VERTEX_SHADER
            );

        glShaderSource(
            vertexShader,
            1,
            &vertexSource,
            nullptr
        );

        glCompileShader(
            vertexShader
        );

        CheckShaderCompile(
            vertexShader,
            "Vertex"
        );

        unsigned int fragmentShader =
            glCreateShader(
                GL_FRAGMENT_SHADER
            );

        glShaderSource(
            fragmentShader,
            1,
            &fragmentSource,
            nullptr
        );

        glCompileShader(
            fragmentShader
        );

        CheckShaderCompile(
            fragmentShader,
            "Fragment"
        );

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

        CheckProgramLink(
            m_RendererID
        );

        glDeleteShader(
            vertexShader
        );

        glDeleteShader(
            fragmentShader
        );
    }

    Shader::~Shader()
    {
        if (m_RendererID != 0)
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

    void Shader::SetInt(
        const std::string& name,
        int value
    )
    {
        GLint location =
            glGetUniformLocation(
                m_RendererID,
                name.c_str()
            );

        glUniform1i(
            location,
            value
        );
    }

    void Shader::SetFloat(
        const std::string& name,
        float value
    )
    {
        GLint location =
            glGetUniformLocation(
                m_RendererID,
                name.c_str()
            );

        glUniform1f(
            location,
            value
        );
    }

    void Shader::SetFloat4(
        const std::string& name,
        const glm::vec4& value
    )
    {
        GLint location =
            glGetUniformLocation(
                m_RendererID,
                name.c_str()
            );

        glUniform4f(
            location,
            value.x,
            value.y,
            value.z,
            value.w
        );
    }

    void Shader::SetMat4(
        const std::string& name,
        const glm::mat4& value
    )
    {
        GLint location =
            glGetUniformLocation(
                m_RendererID,
                name.c_str()
            );

        glUniformMatrix4fv(
            location,
            1,
            GL_FALSE,
            glm::value_ptr(value)
        );
    }

    unsigned int Shader::GetRendererID() const
    {
        return m_RendererID;
    }
}