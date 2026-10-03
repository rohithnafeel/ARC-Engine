#pragma once

struct GLFWwindow;

namespace Arc
{
    class Input
    {
    public:
        static void Init(GLFWwindow* window);

        static bool IsKeyPressed(int key);

    private:
        static GLFWwindow* s_Window;
    };
}