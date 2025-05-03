#include "inputhandler.hpp"

void InputHandler::init(GLFWwindow *glfw_window)
{
    InputHandler::glfw_window = glfw_window;
    current_state = State::MENU;
}

void InputHandler::addCommand(int key, Command* command)
{
    input_map[key] = command;
}
