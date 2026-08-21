#include "Core/TestLayer.h"

#include <iostream>

namespace Arc
{
    void TestLayer::OnAttach()
    {
        std::cout << "Attached: " << m_Name << std::endl;
    }

    void TestLayer::OnDetach()
    {
        std::cout << "Detached: " << m_Name << std::endl;
    }

    void TestLayer::OnUpdate()
    {
        std::cout << "Updating: " << m_Name << std::endl;
    }
}