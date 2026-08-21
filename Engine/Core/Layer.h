#pragma once

#include <string>

namespace Arc
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach();
        virtual void OnDetach();

        virtual void OnUpdate();
        virtual void OnImGuiRender();

        const std::string& GetName() const;

    protected:
        std::string m_Name;
    };
}