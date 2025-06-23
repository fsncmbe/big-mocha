#include <mocha/graphics/camera.hpp>

namespace mocha::graphics {

Camera::Camera() 
{
  position_ = {0, 0, 0};
  front_ = {0, 0, -1};
  up_ = {0, 1, 0};
  world_up_ = up_;
  mouse_pos_ = {0, 0};
  yaw_ = -90.0f;
  pitch_ = 0.0f;
  fov_ = 45.0f;
  movement_speed_ = 5.0f;
  mouse_sensitivity_ = 0.1f;
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

void Camera::update(float dt)
{
  move(dt);
  updateCameraVectors();
}

void Camera::move(float dt)
{
  float velocity = movement_speed_ * dt;
  if (mocha::input::getKeyState(GLFW_KEY_W) == mocha::input::KeyState::Pressed ||
      mocha::input::getKeyState(GLFW_KEY_W) == mocha::input::KeyState::Held)
  {
    position_ += front_ * velocity;
  }

  if (mocha::input::getKeyState(GLFW_KEY_S) == mocha::input::KeyState::Pressed ||
      mocha::input::getKeyState(GLFW_KEY_S) == mocha::input::KeyState::Held)
  {
    position_ -= front_ * velocity;
  }

  if (mocha::input::getKeyState(GLFW_KEY_A) == mocha::input::KeyState::Pressed ||
      mocha::input::getKeyState(GLFW_KEY_A) == mocha::input::KeyState::Held)
  {
    position_ -= right_ * velocity;
  }

  if (mocha::input::getKeyState(GLFW_KEY_D) == mocha::input::KeyState::Pressed ||
      mocha::input::getKeyState(GLFW_KEY_D) == mocha::input::KeyState::Held)
  {
    position_ += right_ * velocity;
  }

  glm::vec2 new_mouse_pos = mocha::input::getMousePos();

  glm::vec2 mouse_offset = {new_mouse_pos.x - mouse_pos_.x, mouse_pos_.y - new_mouse_pos.y};

  mouse_offset *= mouse_sensitivity_;

  mouse_pos_ = new_mouse_pos;

  yaw_ += mouse_offset.x;
  pitch_ += mouse_offset.y;
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

  const float zoom = 45.0f;

  projection_ = glm::perspective(glm::radians(zoom), 1920.0f/1080.0f, 0.1f, 100.0f);
}

}