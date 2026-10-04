#include "HierarchyPanel.h"

#include <imgui.h>

namespace Arc
{
    void HierarchyPanel::Render(Scene& scene)
    {
        ImGui::Begin("Hierarchy");

        int entityIndex = 0;

        for (auto& entity : scene.GetEntities())
        {
            bool selected =
                (m_SelectedEntity == entity.get());

            // Give every entity a stable ImGui ID.
            ImGui::PushID(entityIndex);

            if (ImGui::Selectable(
                    entity->GetName().c_str(),
                    selected))
            {
                m_SelectedEntity =
                    entity.get();
            }

            ImGui::PopID();

            entityIndex++;
        }

        ImGui::Separator();

        // --------------------------------------------------------
        // Create Entity
        // --------------------------------------------------------

        if (ImGui::Button("Create Entity"))
        {
            Entity& entity =
                scene.CreateEntity("Entity");

            m_SelectedEntity = &entity;
        }

        // --------------------------------------------------------
        // Delete Entity
        // --------------------------------------------------------

        if (m_SelectedEntity)
        {
            if (ImGui::Button("Delete Entity"))
            {
                Entity* entityToDelete =
                    m_SelectedEntity;

                m_SelectedEntity = nullptr;

                scene.DestroyEntity(
                    entityToDelete
                );
            }
        }

        ImGui::End();
    }

    Entity* HierarchyPanel::GetSelectedEntity() const
    {
        return m_SelectedEntity;
    }
}