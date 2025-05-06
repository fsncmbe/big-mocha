#include "camera.hpp"

namespace mocha {

Camera::Camera() 
    : position_({0, 0, 0}),
      front_({0, 0, -1}), 
      up_({0, 1, 0}), 
      world_up_(up_),
      yaw_(-90.0f), 
      pitch_(0.0f),
      fov_(45.0f),
      movement_speed_(5.0f), 
      mouse_sensitivity_(0.1f),
      zoom_(45.0f) {
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

void Camera::processKeyboard(Movement dir, float dt)
{
  float velocity = movement_speed_ * dt;
  if (dir == kForward)
      position_ += front_ * velocity;
  if (dir == kBackward)
      position_ -= front_ * velocity;
  if (dir == kLeft)
      position_ -= right_ * velocity;
  if (dir == kRight)
      position_ += right_ * velocity;
}

void Camera::processMouseMovement(float x_offset, float y_offset)
{
  x_offset *= mouse_sensitivity_;
  y_offset *= mouse_sensitivity_;

  yaw_ += x_offset;
  pitch_ += y_offset;

  if (pitch_ > 89.0f)
      pitch_ = 89.0f;
  if (pitch_ < -89.0f)
      pitch_ = -89.9f;
  
      updateCameraVectors();
}

void Camera::processMouseScroll(float offset)
{
  zoom_ -= (float)offset;
  if (zoom_ < 1.0f)
      zoom_ = 1.0f;
  if (zoom_ > 45.0f)
      zoom_ = 45.0f;
}

void Camera::processProjectionChange(glm::vec2 window_size)
{
  projection_ = glm::perspective(glm::radians(fov_), 
                                (float)window_size.x/(float)window_size.y, 
                                0.1f, 100.0f);
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