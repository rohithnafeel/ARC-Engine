#include "InspectorPanel.h"

#include <imgui.h>

#include <cstring>

namespace Arc
{
    void InspectorPanel::Render(Entity* entity)
    {
        ImGui::Begin("Inspector");

        if (!entity)
        {
            ImGui::Text("No entity selected.");

            ImGui::End();

            return;
        }

        if (entity != m_LastEntity)
        {
            std::strncpy(
                m_NameBuffer,
                entity->GetName().c_str(),
                sizeof(m_NameBuffer) - 1
            );

            m_NameBuffer[
                sizeof(m_NameBuffer) - 1
            ] = '\0';

            m_LastEntity = entity;
        }

        ImGui::InputText(
            "Name",
            m_NameBuffer,
            sizeof(m_NameBuffer)
        );

        if (
            ImGui::IsItemDeactivatedAfterEdit()
        )
        {
            if (m_NameBuffer[0] == '\0')
            {
                std::strncpy(
                    m_NameBuffer,
                    "Entity",
                    sizeof(m_NameBuffer) - 1
                );

                m_NameBuffer[
                    sizeof(m_NameBuffer) - 1
                ] = '\0';
            }

            entity->SetName(
                m_NameBuffer
            );
        }

        ImGui::Separator();

        Transform& transform =
            entity->GetTransform();

        if (ImGui::CollapsingHeader(
                "Transform",
                ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::DragFloat3(
                "Position",
                &transform.Position.x,
                0.1f
            );

            ImGui::DragFloat(
                "Rotation",
                &transform.Rotation,
                1.0f
            );

            ImGui::DragFloat3(
                "Scale",
                &transform.Scale.x,
                0.1f
            );
        }

        ImGui::End();
    }
}