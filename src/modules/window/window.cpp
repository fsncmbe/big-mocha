#include "window.hpp"



void Window::init(int window_width, int window_height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfw_window = glfwCreateWindow(window_width, window_height, "Game", NULL, NULL);

    if (glfw_window == NULL)
    {
        std::cout << "Failed to create glfw window" << "\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfw_window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << "\n";
    }
    glViewport(0, 0, window_width, window_height);
}

bool Window::keepGameLoop()
{
    return !glfwWindowShouldClose(glfw_window);
}

void Window::clearWindow()
{
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(glfw_window);
    glfwPollEvents();
}

void Window::closeWindow()
{
    glfwTerminate();
}

Window *Window::instance()
{
    static Window* instance = new Window();
    return instance;
}
