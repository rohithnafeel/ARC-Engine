#include "SandboxApp.h"

#include "Core/TestLayer.h"
#include "Arc/Editor/EditorLayer.h"

namespace Arc
{
    SandboxApp::SandboxApp()
    {
        PushLayer(new TestLayer("GameLayer"));

        PushLayer(new EditorLayer());

        PushOverlay(new TestLayer("DebugOverlay"));
    }
}