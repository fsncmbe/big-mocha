#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <map>
#include <string>

#include "GLFW/glfw3.h"

#include "command.hpp"

// Component
class InputHandler
{
public:
    // State the game can be in in regards to input
    enum class State
    {
        MENU,
        PLAY,
        CUTSCENE
    };
    
    static void init(GLFWwindow* glfw_window);

    // Returns command entity that implements this component
    virtual Command* getCommand() = 0;
    
    // Adds command to input handler, key = GLFW_KEY_...
    void addCommand(int key, Command* command);

protected:
    std::map<int, Command*> input_map;

private:
    static State current_state;
    static GLFWwindow* glfw_window;
};


#endif