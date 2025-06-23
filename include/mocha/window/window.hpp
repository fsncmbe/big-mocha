#ifndef MOCHAWINDOW_HPP
#define MOCHAWINDOW_HPP

#include <iostream>
#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <mocha/helper/log.hpp>

// Input and Window modules in one file, as they kinda codepend on each other, maybe seperate later on 

namespace mocha::window {

namespace {
struct {
  GLFWwindow* glfw_window_;
  float dt_;
  float last_frame_;
  float current_frame_;
} inst;
}

void init();
bool gameLoop();
float* getDT();
}


namespace mocha::input {

enum class KeyState 
{
  None = 0,
  Pressed = 1,
  Held = 2,
  Released = 3
};

namespace {
struct {
std::map<int, mocha::input::KeyState> key_states;
std::map<int, mocha::input::KeyState> mouse_states;
glm::vec2 mouse_pos;
} inst;
}

KeyState getKeyState(int key);
KeyState getMouseKeyState(int key);
glm::vec2 getMousePos();
}

#endif