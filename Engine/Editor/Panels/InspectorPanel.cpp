#include "InspectorPanel.h"

#include <imgui.h>

namespace Arc
{
    void InspectorPanel::Render()
    {
        ImGui::Begin("Inspector");

        ImGui::Text("No object selected.");

        ImGui::End();
    }
}