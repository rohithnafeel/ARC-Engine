#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Arc
{
    class Shader
    {
    public:
        Shader(
            const std::string& vertexSource,
            const std::string& fragmentSource
        );

        ~Shader();

        void Bind() const;
        void Unbind() const;

        void SetMat4(
            const std::string& name,
            const glm::mat4& value
        );

        unsigned int GetRendererID() const;

    private:
        unsigned int m_RendererID = 0;

        int GetUniformLocation(
            const std::string& name
        ) const;
    };
}