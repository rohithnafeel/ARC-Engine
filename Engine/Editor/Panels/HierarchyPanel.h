#pragma once

#include "Arc/Scene/Scene.h"

namespace Arc
{
    class HierarchyPanel
{
public:
    void Render(Scene& scene);

    Entity* GetSelectedEntity() const;

private:
    Entity* m_SelectedEntity = nullptr;
};
}