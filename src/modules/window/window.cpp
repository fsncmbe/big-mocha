#include "window.hpp"



void mocha::window::initWindow(int window_width, int window_height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(window_width, window_height, "Game", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create glfw window" << "\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << "\n";
    }
}

bool mocha::window::keepGameLoop()
{
    return !glfwWindowShouldClose(window);
}

void mocha::window::clearWindow()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mocha::window::swapBuffers()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void mocha::window::closeWindow()
{
    glfwTerminate();
}
