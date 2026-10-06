#pragma once

#include "Arc/Math/Transform.h"
#include "Arc/Scene/SpriteRenderer.h"

#include <string>

namespace Arc
{
    class Entity
    {
    public:
        Entity(
            const std::string& name = "Entity"
        );

        const std::string& GetName() const;

        void SetName(
            const std::string& name
        );

        Transform& GetTransform();

        const Transform& GetTransform() const;

        SpriteRenderer& GetSpriteRenderer();

        const SpriteRenderer&
        GetSpriteRenderer() const;

    private:
        std::string m_Name;

        Transform m_Transform;

        SpriteRenderer m_SpriteRenderer;
    };
}