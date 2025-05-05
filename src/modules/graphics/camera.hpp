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

  Camera(glm::vec3 position = glm::vec3(0.0f));

  glm::mat4   getViewMatrix();
  void        processKeyboard(Movement dir, float dt);
  void        processMouseMovement(float x_offset, float y_offset);
  void        processMouseScroll(float offset);

 private:
  void        updateCameraVectors();

  glm::vec3   position_;
  glm::vec3   front_;
  glm::vec3   up_;
  glm::vec3   right_;
  glm::vec3   world_up_;
  float       yaw_;
  float       pitch_;
  float       movement_speed_;
  float       mouse_sensitivity_;
  float       zoom_;
};

}

#endif