#include "HierarchyPanel.h"

#include <imgui.h>

namespace Arc
{
    void HierarchyPanel::Render()
    {
        ImGui::Begin("Hierarchy");

        ImGui::BulletText("Camera");
        ImGui::BulletText("Triangle");

        ImGui::End();
    }
}