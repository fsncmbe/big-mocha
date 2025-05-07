#include "input.hpp"

namespace mocha {
  std::string Input::keyStateToString(KeyState state)
  {
    switch (state)
    {
      case KeyState::kDown:
        return "kDown";
      case KeyState::kPressed:
        return "kPressed";
      case KeyState::kReleased:
        return "kReleased";
      case KeyState::kUp:
        return "kUp";
      default:
        return "kUnknown";
    }
  }

Input::KeyState Input::getKey(int key)
{
  int key_state = glfwGetKey(Module<Window>::inst()->getGlfwWindow(), key);
  KeyState key_last_state = key_state_map_[key];

  if (key_state == GLFW_PRESS)
  {
    if (key_last_state == KeyState::kUp)
    {
      key_state_map_[key] = KeyState::kPressed;
      return KeyState::kPressed;
    }
    key_state_map_[key] = KeyState::kDown;
    return KeyState::kDown;
  }
  if (key_state == GLFW_RELEASE)
  {
    if (key_last_state == KeyState::kDown)
    {
      key_state_map_[key] = KeyState::kReleased;
      return KeyState::kReleased;
    }
    key_state_map_[key] = KeyState::kUp;
    return KeyState::kUp;
  }
  return KeyState::kUnknown;
}

glm::vec2 Input::getMousePos()
{
  double xpos, ypos;
  glfwGetCursorPos(Module<Window>::inst()->getGlfwWindow(), &xpos, &ypos);
  return glm::vec2(xpos, ypos);
}

}
