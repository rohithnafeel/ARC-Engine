#include "Arc/Editor/EditorLayer.h"

#include <imgui.h>

namespace Arc
{
    void EditorLayer::Begin()
    {
    }

    void EditorLayer::Render()
    {
        ImGui::ShowDemoWindow();
    }

    void EditorLayer::End()
    {
    }
}