#include <mocha/window/window.hpp>

namespace {

struct {
  GLFWwindow* glfw_window_;
  float dt_;
  float last_frame_;
  float current_frame_;
} inst;

void windowSizeChange(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

}

namespace mocha::window {

void init()
{
  if (!glfwInit())
  {
    mocha::log(mocha::LogLevel::ERROR, "GLFW INIT FAILED");
    glfwTerminate();
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Hard coded window size, change after initial launch
  inst.glfw_window_ = glfwCreateWindow(1920, 1080, "Engine", NULL, NULL);

  if (!inst.glfw_window_)
  {
    mocha::log(mocha::LogLevel::ERROR, "GLFW WINDOW FAILED");
    glfwTerminate();
  }

  glfwMakeContextCurrent(inst.glfw_window_);
  glfwSetFramebufferSizeCallback(inst.glfw_window_, windowSizeChange);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    mocha::log(mocha::LogLevel::ERROR, "GLAD FAILED");
  }

  glfwSetInputMode(inst.glfw_window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

  glEnable(GL_DEPTH_TEST);

  inst.current_frame_, inst.last_frame_ = glfwGetTime();
  inst.dt_ = 0;
};

bool gameLoop()
{
  // END OF LAST FRAME
  glfwSwapBuffers(inst.glfw_window_);
  glfwPollEvents();

  // BETWEEN FRAMES
  inst.current_frame_ = glfwGetTime();
  inst.dt_ = inst.current_frame_ - inst.last_frame_;
  inst.last_frame_ = inst.current_frame_;

  // BEGINNING OF NEXT FRAME
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  return !glfwWindowShouldClose(inst.glfw_window_);
}

float* getDT()
{
  return &inst.dt_;
}

}