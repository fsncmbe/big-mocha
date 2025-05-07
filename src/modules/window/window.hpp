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
  void changeCursorCapture();
  bool getCursorCapture() {return cursor_captured_;}
  float getDt() {return dt_;}
  GLFWwindow* getGlfwWindow() {return glfw_window_;}

  // Subject
  Subject* getSubject();

 private:
  Window() {};
  GLFWwindow* glfw_window_;
  float dt_;
  float last_frame_;
  float current_frame_;
  bool cursor_captured_;

  // Subject
  Subject subject_;
};

}
#endif