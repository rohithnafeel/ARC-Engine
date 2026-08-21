#include "SandboxApp.h"

#include "Core/TestLayer.h"

namespace Arc
{
    SandboxApp::SandboxApp()
    {
        PushLayer(new TestLayer("GameLayer"));
        PushOverlay(new TestLayer("DebugOverlay"));
    }
}