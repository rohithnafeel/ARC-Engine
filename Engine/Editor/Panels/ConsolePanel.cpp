#include "ConsolePanel.h"

#include <imgui.h>

namespace Arc
{
    void ConsolePanel::Render()
    {
        ImGui::Begin("Console");

        ImGui::Text("HI  THERE >_<");

        ImGui::End();
    }
}