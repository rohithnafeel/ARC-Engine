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

    private:
        GLFWwindow* m_Window = nullptr;
        LayerStack m_LayerStack;
    };
}