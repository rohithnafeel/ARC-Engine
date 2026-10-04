#pragma once

#include "Arc/Scene/Entity.h"

#include <vector>
#include <memory>

namespace Arc
{
    class Scene
    {
    public:
        Scene() = default;
        ~Scene() = default;

        Entity& CreateEntity(
            const std::string& name = "Entity"
        );

        void DestroyEntity(Entity* entity);

        std::vector<std::unique_ptr<Entity>>&
        GetEntities();

    private:
        std::vector<std::unique_ptr<Entity>> m_Entities;
    };
}