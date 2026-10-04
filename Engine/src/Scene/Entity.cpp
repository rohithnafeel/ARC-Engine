#include "Arc/Scene/Entity.h"

namespace Arc
{
    Entity::Entity(const std::string& name)
        : m_Name(name)
    {
    }

    const std::string& Entity::GetName() const
    {
        return m_Name;
    }

    void Entity::SetName(const std::string& name)
{
    m_Name = name;
}

    Transform& Entity::GetTransform()
    {
        return m_Transform;
    }

    const Transform& Entity::GetTransform() const
    {
        return m_Transform;
    }
}