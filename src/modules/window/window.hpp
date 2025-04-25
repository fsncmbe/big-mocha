#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../module.hpp"

class Window : public Module
{
public:
    static Window* instance();
    void init(int window_width, int window_height);
    bool keepGameLoop();
    void clearWindow();
    void swapBuffers();
    void closeWindow();
private:
    Window() {};
    GLFWwindow* glfw_window;
};

#endif