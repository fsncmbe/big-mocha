#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

enum CameraMovement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
public:
    glm::vec3   position;
    glm::vec3   front;
    glm::vec3   up;
    glm::vec3   right;
    glm::vec3   world_up;

    float       yaw;
    float       pitch;
    
    float       movement_speed;
    float       mouse_sensitivity;
    float       zoom;

    Camera(glm::vec3 position = glm::vec3(0.0f));

    glm::mat4   getViewMatrix();
    void        processKeyboard(CameraMovement c_m, float delta_time);
    void        processMouseMovement(float x_offset, float y_offset);
    void        processMouseScroll(float offset);

private:
    void        updateCameraVectors();
};



#endif