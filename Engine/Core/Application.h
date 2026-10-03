#pragma once

#include "Core/LayerStack.h"

struct GLFWwindow;

namespace Arc
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        static float GetDeltaTime();

    private:
        GLFWwindow* m_Window = nullptr;

        LayerStack m_LayerStack;

        float m_DeltaTime = 0.0f;
        float m_LastFrameTime = 0.0f;

        static Application* s_Instance;
    };
}