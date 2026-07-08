#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
    std::cout << "Starting Arc Engine...\n";

    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!\n";
        return -1;
    }

    // Tell GLFW which OpenGL version we want
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Arc Engine", nullptr, nullptr);

    if (!window)
    {
        std::cout << "Failed to create window!\n";
        glfwTerminate();
        return -1;
    }

    std::cout << "Window created successfully!\n";

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD!\n";
        return -1;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}