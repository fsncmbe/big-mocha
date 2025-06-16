#ifndef MOCHACAMERA_HPP
#define MOCHACAMERA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mocha::graphics {

class Camera
{
 public:
  Camera();

  glm::mat4   getViewMatrix();
  glm::mat4   getProjectionMatrix();
  glm::vec3   getPosition();
  void        update(float dt);

 private:
  void        updateCameraVectors();

  glm::mat4   projection_;
  glm::vec3   position_;
  glm::vec3   front_;
  glm::vec3   up_;
  glm::vec3   right_;
  glm::vec3   world_up_;
  glm::vec2   mouse_pos_;
  float       yaw_;
  float       pitch_;
  float       fov_;
  float       movement_speed_;
  float       mouse_sensitivity_;
};

}
#endif