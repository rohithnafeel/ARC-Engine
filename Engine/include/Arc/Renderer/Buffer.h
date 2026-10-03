#pragma once

#include <string>
#include <vector>

namespace Arc
{
    enum class ShaderDataType
    {
        None = 0,

        Float,
        Float2,
        Float3,
        Float4,

        Mat3,
        Mat4,

        Int,
        Int2,
        Int3,
        Int4,

        Bool
    };

    class BufferElement
    {
    public:
        std::string Name;
        ShaderDataType Type;

        unsigned int Size;
        unsigned int Offset;

        bool Normalized;

        BufferElement(
            ShaderDataType type,
            const std::string& name,
            bool normalized = false
        );

        unsigned int GetComponentCount() const;
    };

    class BufferLayout
    {
    public:
        BufferLayout() = default;

        BufferLayout(
            const std::initializer_list<BufferElement>& elements
        );

        unsigned int GetStride() const;

        const std::vector<BufferElement>& GetElements() const;

        std::vector<BufferElement>::iterator begin();
        std::vector<BufferElement>::iterator end();

        std::vector<BufferElement>::const_iterator begin() const;
        std::vector<BufferElement>::const_iterator end() const;

    private:
        void CalculateOffsetsAndStride();

    private:
        std::vector<BufferElement> m_Elements;

        unsigned int m_Stride = 0;
    };
}