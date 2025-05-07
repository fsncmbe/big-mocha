#include "camera.hpp"

namespace mocha {

Camera::Camera() 
    : position_({0, 0, 0}),
      front_({0, 0, -1}), 
      up_({0, 1, 0}),
      world_up_(up_),
      mouse_pos_({0, 0}),
      yaw_(-90.0f), 
      pitch_(0.0f),
      fov_(45.0f),
      movement_speed_(5.0f),
      mouse_sensitivity_(0.1f) {
  updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
  return glm::lookAt(position_, position_+front_, up_);
}

glm::mat4 Camera::getProjectionMatrix()
{
  return projection_;
}

void Camera::processProjectionChange(glm::vec2 window_size)
{
  projection_ = glm::perspective(glm::radians(fov_), 
                                (float)window_size.x/(float)window_size.y, 
                                0.1f, 100.0f);
}

void Camera::update()
{
  float dt = Module<Window>::inst()->getDt();
  keyMovement(dt);
  mouseMovement(dt);
  updateCameraVectors();
}

void Camera::keyMovement(float dt)
{
  Input::KeyState W = Module<Input>::inst()->getKey(GLFW_KEY_W);
  Input::KeyState S = Module<Input>::inst()->getKey(GLFW_KEY_S);
  Input::KeyState D = Module<Input>::inst()->getKey(GLFW_KEY_D);
  Input::KeyState A = Module<Input>::inst()->getKey(GLFW_KEY_A);
  Input::KeyState E = Module<Input>::inst()->getKey(GLFW_KEY_E);
  Input::KeyState LALT = Module<Input>::inst()->getKey(GLFW_KEY_LEFT_ALT);

  if (W == Input::KeyState::kDown)
    position_ += front_ * (movement_speed_ * dt);
  if (S == Input::KeyState::kDown)
    position_ -= front_ * (movement_speed_ * dt);
  if (D == Input::KeyState::kDown)
    position_ += right_ * (movement_speed_ * dt);
  if (A == Input::KeyState::kDown)
    position_ -= right_ * (movement_speed_ * dt);
  
  if (E == Input::KeyState::kPressed)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  if (E == Input::KeyState::kReleased)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  if (LALT == Input::KeyState::kPressed || LALT == Input::KeyState::kReleased)
    Module<Window>::inst()->changeCursorCapture();
}

void Camera::mouseMovement(float dt)
{
  glm::vec2 new_mouse_pos = Module<Input>::inst()->getMousePos();

  static bool firstMouse = true;
  if (firstMouse)
  { 
    mouse_pos_ = new_mouse_pos;
    firstMouse = false;
  }
  
  glm::vec2 offset = {new_mouse_pos.x - mouse_pos_.x, mouse_pos_.y - new_mouse_pos.y};
  offset *= mouse_sensitivity_;
  mouse_pos_ = new_mouse_pos;

  if (Module<Window>::inst()->getCursorCapture())
  {
    yaw_ += offset.x;
    pitch_ += offset.y;

    if (pitch_ > 89.0f)
        pitch_ = 89.0f;
    if (pitch_ < -89.0f)
        pitch_ = -89.9f;
  }
}

void Camera::updateCameraVectors()
{
  glm::vec3 t_front;
  t_front.x  = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  t_front.y  = sin(glm::radians(pitch_));
  t_front.z  = sin(glm::radians(yaw_ * cos(glm::radians(pitch_))));
  front_ = glm::normalize(t_front);

  right_ = glm::normalize(glm::cross(front_, world_up_));
  up_ = glm::normalize(glm::cross(right_, front_));
}
}