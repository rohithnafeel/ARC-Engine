#pragma once

#include "Arc/Math/Transform.h"

#include <string>

namespace Arc
{
    class Entity
    {
    public:
        Entity(const std::string& name = "Entity");

        const std::string& GetName() const;
        void SetName(const std::string& name);

        Transform& GetTransform();
        const Transform& GetTransform() const;

    private:
        std::string m_Name;
        Transform m_Transform;
    };
}