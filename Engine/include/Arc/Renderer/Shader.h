#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Arc
{
    class Shader
    {
    public:
        Shader(
            const char* vertexSource,
            const char* fragmentSource
        );

        ~Shader();

        void Bind() const;
        void Unbind() const;

        void SetInt(
            const std::string& name,
            int value
        );

        void SetFloat(
            const std::string& name,
            float value
        );

        void SetFloat4(
            const std::string& name,
            const glm::vec4& value
        );

        void SetMat4(
            const std::string& name,
            const glm::mat4& value
        );

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;
    };
}