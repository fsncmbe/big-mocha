#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../window/input.hpp"

namespace mocha {

class Camera
{
 public:

  Camera();

  glm::mat4   getViewMatrix();
  glm::mat4   getProjectionMatrix();
  void        processProjectionChange(glm::vec2 window_size);
  glm::vec3   getPosition() {return position_;}
  void        update();
 private:
  void        updateCameraVectors();
  void        keyMovement(float dt);
  void        mouseMovement(float dt);
  
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