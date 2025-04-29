#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../module.hpp"
#include "../event/subject.hpp"

class Window : public Module
{
public:
    static Window* instance();
    void init(int window_width, int window_height);
    bool keepGameLoop();
    void clearWindow();
    void swapBuffers();
    void closeWindow();

    // Subject
    Subject* getSubject();
    
private:
    Window() {};
    GLFWwindow* glfw_window;

    // Subject
    Subject subject;
};

#endif