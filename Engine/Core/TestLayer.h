#pragma once

#include "Core/Layer.h"

namespace Arc
{
    class TestLayer : public Layer
    {
    public:
        TestLayer(const std::string& name)
            : Layer(name)
        {
        }

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
    };
}