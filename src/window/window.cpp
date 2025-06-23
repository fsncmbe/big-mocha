#include <mocha/window/window.hpp>

namespace mocha::input {

namespace {
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_UNKNOWN) return;
  using KeyState = mocha::input::KeyState;
  mocha::input::KeyState& state = mocha::input::inst.key_states[key];

  if (action == GLFW_PRESS)
  {
    if (state == KeyState::None || state == KeyState::Released)
    {
      state = KeyState::Pressed;
    }
  }
  else if (action == GLFW_RELEASE)
  {
    state = KeyState::Released;
  }
}

void mouseKeyCallback(GLFWwindow* window, int key, int action, int mods)
{
  if (key == GLFW_KEY_UNKNOWN) return;

  using KeyState = mocha::input::KeyState;
  mocha::input::KeyState& state = mocha::input::inst.mouse_states[key];

  if (action == GLFW_PRESS)
  {
    if (state == KeyState::None || state == KeyState::Released)
    {
      state = KeyState::Pressed;
    }
  }
  else if (action == GLFW_RELEASE)
  {
    state = KeyState::Released;
  }
}

void mousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
  mocha::input::inst.mouse_pos = glm::vec2(xpos, ypos);
}

void changeKeyState()
{
  using KeyState = mocha::input::KeyState;

  for (auto& pair : inst.key_states)
  {
    KeyState& state = pair.second;
    
    if (state == KeyState::Pressed)
    {
      state == KeyState::Held;
    }
    else if (state == KeyState::Released)
    {
      state == KeyState::None;
    }
  }

  for (auto& pair : mocha::input::inst.mouse_states)
  {
    KeyState& state = pair.second;
    
    if (state == KeyState::Pressed)
    {
      state == KeyState::Held;
    }
    else if (state == KeyState::Released)
    {
      state == KeyState::None;
    }
  }
}
}

KeyState getKeyState(int key)
{
  return mocha::input::inst.key_states[key];
}

KeyState getMouseKeyState(int key)
{
  return mocha::input::inst.mouse_states[key];
}

glm::vec2 getMousePos()
{
  return mocha::input::inst.mouse_pos;
}
}




namespace mocha::window {

namespace {
void windowSizeChange(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}
}

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
  mocha::window::inst.glfw_window_ = glfwCreateWindow(1920, 1080, "Engine", NULL, NULL);

  if (!mocha::window::inst.glfw_window_)
  {
    mocha::log(mocha::LogLevel::ERROR, "GLFW WINDOW FAILED");
    glfwTerminate();
  }

  glfwMakeContextCurrent(mocha::window::inst.glfw_window_);
  glfwSetFramebufferSizeCallback(mocha::window::inst.glfw_window_, windowSizeChange);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    mocha::log(mocha::LogLevel::ERROR, "GLAD FAILED");
  }

  glfwSetInputMode(mocha::window::inst.glfw_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glEnable(GL_DEPTH_TEST);

  // Input callbacks
  glfwSetKeyCallback(mocha::window::inst.glfw_window_, mocha::input::keyCallback);
  glfwSetMouseButtonCallback(mocha::window::inst.glfw_window_, mocha::input::mouseKeyCallback);
  glfwSetCursorPosCallback(mocha::window::inst.glfw_window_, mocha::input::mousePosCallback);

  mocha::window::inst.current_frame_, mocha::window::inst.last_frame_ = glfwGetTime();
  mocha::window::inst.dt_ = 0;
};

bool gameLoop()
{
  // END OF LAST FRAME
  glfwSwapBuffers(mocha::window::inst.glfw_window_);
  glfwPollEvents();

  // BETWEEN FRAMES
  mocha::window::inst.current_frame_ = glfwGetTime();
  mocha::window::inst.dt_ = mocha::window::inst.current_frame_ - mocha::window::inst.last_frame_;
  mocha::window::inst.last_frame_ = mocha::window::inst.current_frame_;

  // INPUT STATE CHANGE
  mocha::input::changeKeyState();

  // BEGINNING OF NEXT FRAME
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  return !glfwWindowShouldClose(mocha::window::inst.glfw_window_);
}

float* getDT()
{
  return &mocha::window::inst.dt_;
}

}