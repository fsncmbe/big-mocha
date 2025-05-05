#include "body3d.hpp"

namespace mocha {

Cube::Cube(glm::vec3 size)
{
  glm::vec3 size_n = size;
  float vertices[] = {
    -size_n.x, -size_n.y, -size_n.z,
     size_n.x, -size_n.y, -size_n.z,
     size_n.x, -size_n.y,  size_n.z,
    -size_n.x, -size_n.y,  size_n.z,
    -size_n.x,  size_n.y,  size_n.z,
     size_n.x,  size_n.y,  size_n.z,
     size_n.x,  size_n.y, -size_n.z,
    -size_n.x,  size_n.y, -size_n.z,
  };

  unsigned int indices[] = {
    // Bottom
    0, 1, 2,
    2, 3, 0,
    // Front
    3, 2, 5,
    5, 4, 3,
    // Left
    0, 3, 4,
    4, 7, 0,
    // Back
    1, 0, 7,
    7, 6, 1,
    // Right
    2, 1, 6, 
    6, 5, 2,
    // Top
    4, 5, 6,
    6, 7, 4
  };

  unsigned int vbo, ebo;
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);
  
  glBindVertexArray(vao_);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &ebo);
}

void Cube::draw()
{
  glBindVertexArray(vao_);
  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

Ball::Ball(float radius)
{
  
}

void Ball::draw()
{

}

Plane::Plane(glm::vec2 size)
{

}

void Plane::draw()
{

}

Model::Model()
{

}

void Model::draw()
{

}

}