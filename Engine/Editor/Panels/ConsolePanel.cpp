#include "ConsolePanel.h"

#include <imgui.h>

namespace Arc
{
    void ConsolePanel::Render()
    {
        ImGui::Begin("Console");

        ImGui::Text("Arc Engine started successfully.");

        ImGui::End();
    }
}