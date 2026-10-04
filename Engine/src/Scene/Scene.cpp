#include "Arc/Scene/Scene.h"

namespace Arc
{

    void Scene::DestroyEntity(Entity* entity)
{
    if (!entity)
        return;

    for (auto it = m_Entities.begin();
         it != m_Entities.end();
         ++it)
    {
        if (it->get() == entity)
        {
            m_Entities.erase(it);
            return;
        }
    }
}

    Entity& Scene::CreateEntity(
        const std::string& name
    )
    {
        m_Entities.push_back(
            std::make_unique<Entity>(name)
        );

        return *m_Entities.back();
    }

    std::vector<std::unique_ptr<Entity>>&
    Scene::GetEntities()
    
    {
        return m_Entities;
    }
}