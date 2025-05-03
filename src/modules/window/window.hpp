#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <map>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../module.hpp"
#include "../event/subject.hpp"

class Window : public Module
{
public:
    // Window
    static Window* instance();
    void init(int window_width, int window_height);
    bool keepGameLoop();
    void clearWindow();
    void swapBuffers();
    void closeWindow();

    // Input
    void getInputs();

    // Subject
    Subject* getSubject();
    
private:
    Window() {};
    GLFWwindow* glfw_window;

    // Input
    std::map<std::string, int> keys = {
        {"W", GLFW_KEY_W},
        {"A", GLFW_KEY_A},
        {"S", GLFW_KEY_S},
        {"D", GLFW_KEY_D}
    };

    // Subject
    Subject subject;
};

#endif