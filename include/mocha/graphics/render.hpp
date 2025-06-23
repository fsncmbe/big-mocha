#ifndef MOCHARENDER_HPP
#define MOCHARENDER_HPP

#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include <mocha/graphics/camera.hpp>
#include <mocha/graphics/drawables.hpp>

namespace mocha::graphics {

void setShader(Shader* shader);
void updateShaders(float dt);

void setCamera(Camera* camera);
Camera* getCamera();

void update(float dt);

void draw(Model &model_, glm::vec3 pos, glm::vec3 color);
}
#endif