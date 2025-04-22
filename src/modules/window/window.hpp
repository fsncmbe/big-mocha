#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace mocha{
namespace window
{
    inline GLFWwindow* window;

    void initWindow(int window_width, int window_height);
    bool keepGameLoop();
    void clearWindow();
    void swapBuffers();
    void closeWindow();
}
}

#endif