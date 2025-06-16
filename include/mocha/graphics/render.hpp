#ifndef MOCHARENDER_HPP
#define MOCHARENDER_HPP

#include <iostream>

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include <mocha/graphics/camera.hpp>
#include <mocha/graphics/drawables.hpp>

namespace mocha::graphics {

void setShader(Shader* shader);
void updateShaders(float dt);

void genCubeData();
void draw(Texture &tex, glm::vec2 pos, glm::vec2 size, float rotate, glm::vec3 color);
}
#endif