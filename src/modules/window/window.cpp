#include "window.hpp"

namespace {

void windowSizeChange(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
  mocha::Module<mocha::Window>::inst()->getSubject()->notifyObservers(new mocha::Event(mocha::Event::Type::kWindowSizeChange, "", 0, 0.0f, {width, height, 0}));
}

}

namespace mocha {

void Window::init(glm::vec2 window_size)
{
  if (!glfwInit())
  {
    subject_.notifyObservers(new Event(Event::Type::kLogError, "Failed to init glfw"));
    glfwTerminate();
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfw_window_ = glfwCreateWindow(window_size.x, window_size.y, "Game", NULL, NULL);

  if (!glfw_window_)
  {
    subject_.notifyObservers(new Event(Event::Type::kLogError, "Failed to create glfw window"));
    glfwTerminate();
  }

  glfwMakeContextCurrent(glfw_window_);
  glfwSetFramebufferSizeCallback(glfw_window_, windowSizeChange);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    subject_.notifyObservers(new Event(Event::Type::kLogError, "Failed to init glad"));
    closeWindow();
  }

  glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  cursor_captured_ = true;

  current_frame_ = glfwGetTime();
  dt_ = 0;
  last_frame_ = current_frame_;

  subject_.notifyObservers(new Event(Event::Type::kLogSuccess, "Window init done"));
}

bool Window::keepGameLoop()
{
  updateDt();
  return !glfwWindowShouldClose(glfw_window_);
}

void Window::updateDt()
{
  current_frame_ = glfwGetTime();
  dt_ = current_frame_ - last_frame_;
  last_frame_ = current_frame_;
}

void Window::clearWindow()
{
  glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers()
{
  glfwSwapBuffers(glfw_window_);
  glfwPollEvents();
}

void Window::closeWindow()
{
  glfwDestroyWindow(glfw_window_);
  glfwTerminate();
}

void Window::changeCursorCapture()
{
  if (cursor_captured_)
  {
    glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
    cursor_captured_ = false;
  } else {
    glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    cursor_captured_ = true;
  }
}

Subject* Window::getSubject()
{
  return &subject_;
}

}