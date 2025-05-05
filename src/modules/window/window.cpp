#include "window.hpp"

namespace {

void windowSizeChange(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
  mocha::Module<mocha::Window>::inst()->getSubject()->notifyObservers(new mocha::Event(mocha::Event::Type::kWindowSizeChange, "", 0, {width, height, 0}));
}

}


namespace mocha {

void Window::init(glm::vec2 window_size)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfw_window_ = glfwCreateWindow(window_size.x, window_size.y, "Game", NULL, NULL);

  if (glfw_window_ == NULL)
  {
    std::cout << "Failed to create glfw window" << "\n";
    glfwTerminate();
  }

  glfwMakeContextCurrent(glfw_window_);
  glfwSetFramebufferSizeCallback(glfw_window_, windowSizeChange);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << "\n";
  }

  subject_.notifyObservers(new Event(Event::Type::kLogSuccess, "Window init done"));
}

bool Window::keepGameLoop()
{
  return !glfwWindowShouldClose(glfw_window_);
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
  glfwTerminate();
}

void Window::getInputs()
{
  for (auto &pair : keys_map_)
  {
    //if (glfwGetKey(Module<Window>::inst()->glfw_window_, pair.second) == GLFW_PRESS)
    //  subject_.notifyObservers(new Event(Event::Type::kKeyDown, pair.first));
    //if (glfwGetKey(Module<Window>::inst()->glfw_window_, pair.second) == GLFW_RELEASE)
    //  subject_.notifyObservers(new Event(Event::Type::kKeyUp, pair.first));
  }
}

Subject* Window::getSubject()
{
  return &subject_;
}

}