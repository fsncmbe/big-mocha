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

glm::vec3 Camera::getPosition()
{
  return glm::vec3();
}

void Camera::update(float dt)
{
  //mouseMovement(dt);
  //keyMovement(dt);
  updateCameraVectors();
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