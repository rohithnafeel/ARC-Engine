#include "Core/Layer.h"

namespace Arc
{
    Layer::Layer(const std::string& name)
        : m_Name(name)
    {
    }

    void Layer::OnAttach()
    {
    }

    void Layer::OnDetach()
    {
    }

    void Layer::OnUpdate()
    {
    }

    void Layer::OnImGuiRender()
    {
    }

    const std::string& Layer::GetName() const
    {
        return m_Name;
    }
}