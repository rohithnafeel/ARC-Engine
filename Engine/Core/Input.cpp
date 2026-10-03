#include "Input.h"

#include <GLFW/glfw3.h>

namespace Arc
{
    GLFWwindow* Input::s_Window = nullptr;

    void Input::Init(GLFWwindow* window)
    {
        s_Window = window;
    }

    bool Input::IsKeyPressed(int key)
    {
        if (!s_Window)
            return false;

        return glfwGetKey(
            s_Window,
            key
        ) == GLFW_PRESS;
    }
}