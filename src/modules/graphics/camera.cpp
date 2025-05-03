#include "camera.hpp"

Camera::Camera(glm::vec3 position) :
position(position), 
front({0, 0, -1}), 
up({0, 1, 0}), 
world_up(up),
yaw(-90.0f), 
pitch(0.0f), 
movement_speed(2.5f), 
mouse_sensitivity(0.1f),
zoom(45.0f)
{
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position+front, up);
}

void Camera::processKeyboard(CameraMovement dir, float delta_time)
{
    float velocity = movement_speed * delta_time;
    if (dir == FORWARD)
        position += front * velocity;
    if (dir == BACKWARD)
        position -= front * velocity;
    if (dir == LEFT)
        position -= right * velocity;
    if (dir == RIGHT)
        position += right * velocity;
}

void Camera::processMouseMovement(float x_offset, float y_offset)
{
    x_offset *= mouse_sensitivity;
    y_offset *= mouse_sensitivity;

    yaw += x_offset;
    pitch += y_offset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.9f;
    
        updateCameraVectors();
}

void Camera::processMouseScroll(float offset)
{
    zoom -= (float)offset;
    if (zoom < 1.0f)
        zoom = 1.0f;
    if (zoom > 45.0f)
        zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    glm::vec3 t_front;
    t_front.x  = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    t_front.y  = sin(glm::radians(pitch));
    t_front.z  = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(t_front);

    right = glm::normalize(glm::cross(front, world_up));
    up = glm::normalize(glm::cross(right, front));
}
