#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace mocha {

class Camera
{
 public:
  enum Movement
  {
    kForward,
    kBackward,
    kLeft,
    kRight
  };

  Camera();

  glm::mat4   getViewMatrix();
  glm::mat4   getProjectionMatrix();
  void        processKeyboard(Movement dir, float dt);
  void        processMouseMovement(float x_offset, float y_offset);
  void        processMouseScroll(float offset);
  void        processProjectionChange(glm::vec2 window_size);

 private:
  void        updateCameraVectors();

  glm::mat4   projection_;
  glm::vec3   position_;
  glm::vec3   front_;
  glm::vec3   up_;
  glm::vec3   right_;
  glm::vec3   world_up_;
  float       yaw_;
  float       pitch_;
  float       fov_;
  float       movement_speed_;
  float       mouse_sensitivity_;
  float       zoom_;
};

}

#endif