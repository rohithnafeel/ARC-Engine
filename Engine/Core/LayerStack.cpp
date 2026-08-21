#include "Core/LayerStack.h"

#include <algorithm>

namespace Arc
{
    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_Layers.emplace(
            m_Layers.begin() + m_LayerInsertIndex,
            layer
        );

        m_LayerInsertIndex++;

        layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);

        overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto iterator = std::find(
            m_Layers.begin(),
            m_Layers.begin() + m_LayerInsertIndex,
            layer
        );

        if (iterator != m_Layers.begin() + m_LayerInsertIndex)
        {
            (*iterator)->OnDetach();

            m_Layers.erase(iterator);

            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto iterator = std::find(
            m_Layers.begin() + m_LayerInsertIndex,
            m_Layers.end(),
            overlay
        );

        if (iterator != m_Layers.end())
        {
            (*iterator)->OnDetach();

            m_Layers.erase(iterator);
        }
    }
}