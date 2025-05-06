#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <map>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "../module.hpp"
#include "../event/subject.hpp"

namespace {
  void windowSizeChange(GLFWwindow* window, int width, int height);
}

namespace mocha {

class Window
{
 friend class Module<Window>;
 public:
  void init(glm::vec2 window_size);
  bool keepGameLoop();
  void updateDt();
  void clearWindow();
  void swapBuffers();
  void closeWindow();

  // Input
  void getInputs();

  // Subject
  Subject* getSubject();

 private:
  Window() {};
  GLFWwindow* glfw_window_;
  float dt_;
  float last_frame_;
  float current_frame_;

  // Input
  std::map<std::string, int> keys_map_ = {
    {"W", GLFW_KEY_W},
    {"A", GLFW_KEY_A},
    {"S", GLFW_KEY_S},
    {"D", GLFW_KEY_D}
  };

  // Subject
  Subject subject_;
};

}
#endif