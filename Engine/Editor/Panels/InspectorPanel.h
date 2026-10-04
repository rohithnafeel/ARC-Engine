#pragma once

#include "Arc/Scene/Entity.h"

namespace Arc
{
    class InspectorPanel
    {
    public:
        void Render(Entity* entity);

    private:
        char m_NameBuffer[256] = {};
        Entity* m_LastEntity = nullptr;
    };
}