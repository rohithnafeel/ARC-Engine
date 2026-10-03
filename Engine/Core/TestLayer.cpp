#include "TestLayer.h"

#include <iostream>

namespace Arc
{
    void TestLayer::OnAttach()
    {
        std::cout
            << "Attached: "
            << m_Name
            << "\n";
    }

    void TestLayer::OnDetach()
    {
        std::cout
            << "Detached: "
            << m_Name
            << "\n";
    }

    void TestLayer::OnUpdate()
    {
        // Nothing here for now.
    }
}