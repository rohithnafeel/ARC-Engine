#pragma once

#include "Core/Layer.h"

#include "Arc/Renderer/Framebuffer.h"
#include "Arc/Renderer/Texture2D.h"
#include "Renderer/Camera/OrthographicCamera.h"

#include "Arc/Scene/Scene.h"

#include "Dockspace.h"

#include "Panels/ViewportPanel.h"
#include "Panels/HierarchyPanel.h"
#include "Panels/InspectorPanel.h"
#include "Panels/ConsolePanel.h"

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
        OrthographicCamera m_Camera;

        std::unique_ptr<Framebuffer> m_Framebuffer;

        std::unique_ptr<Scene> m_Scene;

        Dockspace m_Dockspace;

        ViewportPanel m_ViewportPanel;
        HierarchyPanel m_HierarchyPanel;
        InspectorPanel m_InspectorPanel;
        ConsolePanel m_ConsolePanel;
    };
}