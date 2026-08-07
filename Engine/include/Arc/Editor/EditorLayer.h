#pragma once

#include "ViewportPanel.h"
#include "HierarchyPanel.h"
#include "InspectorPanel.h"
#include "ConsolePanel.h"
#include "Dockspace.h"

namespace Arc
{
    class Framebuffer;

    class EditorLayer
    {
    public:
        void Begin();
        void Render(Framebuffer& framebuffer);
        void End();

    private:
        Dockspace m_Dockspace;
        ViewportPanel m_ViewportPanel;
        HierarchyPanel m_HierarchyPanel;
        InspectorPanel m_InspectorPanel;
        ConsolePanel m_ConsolePanel;
    };
}