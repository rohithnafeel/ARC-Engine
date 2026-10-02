#pragma once

#include "Core/Layer.h"
#include "Dockspace.h"
#include "ViewportPanel.h"
#include "HierarchyPanel.h"
#include "InspectorPanel.h"
#include "ConsolePanel.h"

#include "Arc/Renderer/Framebuffer.h"
#include "Renderer/Camera/OrthographicCamera.h"
#include <memory>

namespace Arc
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnImGuiRender() override;

    private:
        Dockspace m_Dockspace;

        ViewportPanel m_ViewportPanel;
        HierarchyPanel m_HierarchyPanel;
        InspectorPanel m_InspectorPanel;
        ConsolePanel m_ConsolePanel;

        std::unique_ptr<Framebuffer> m_Framebuffer;

        OrthographicCamera m_Camera;
    };
}