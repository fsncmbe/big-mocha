#include "body3d.hpp"

namespace mocha {

Cube::Cube(glm::vec3 size)
{
  float size_n = size.x;
  float vertices[] = {
    -size_n, -size_n, -size_n,  0.0f,  0.0f, -1.0f,
     size_n, -size_n, -size_n,  0.0f,  0.0f, -1.0f,
     size_n,  size_n, -size_n,  0.0f,  0.0f, -1.0f,
     size_n,  size_n, -size_n,  0.0f,  0.0f, -1.0f,
    -size_n,  size_n, -size_n,  0.0f,  0.0f, -1.0f,
    -size_n, -size_n, -size_n,  0.0f,  0.0f, -1.0f,

    -size_n, -size_n,  size_n,  0.0f,  0.0f,  1.0f,
     size_n, -size_n,  size_n,  0.0f,  0.0f,  1.0f,
     size_n,  size_n,  size_n,  0.0f,  0.0f,  1.0f,
     size_n,  size_n,  size_n,  0.0f,  0.0f,  1.0f,
    -size_n,  size_n,  size_n,  0.0f,  0.0f,  1.0f,
    -size_n, -size_n,  size_n,  0.0f,  0.0f,  1.0f,

    -size_n,  size_n,  size_n, -1.0f,  0.0f,  0.0f,
    -size_n,  size_n, -size_n, -1.0f,  0.0f,  0.0f,
    -size_n, -size_n, -size_n, -1.0f,  0.0f,  0.0f,
    -size_n, -size_n, -size_n, -1.0f,  0.0f,  0.0f,
    -size_n, -size_n,  size_n, -1.0f,  0.0f,  0.0f,
    -size_n,  size_n,  size_n, -1.0f,  0.0f,  0.0f,

     size_n,  size_n,  size_n,  1.0f,  0.0f,  0.0f,
     size_n,  size_n, -size_n,  1.0f,  0.0f,  0.0f,
     size_n, -size_n, -size_n,  1.0f,  0.0f,  0.0f,
     size_n, -size_n, -size_n,  1.0f,  0.0f,  0.0f,
     size_n, -size_n,  size_n,  1.0f,  0.0f,  0.0f,
     size_n,  size_n,  size_n,  1.0f,  0.0f,  0.0f,

    -size_n, -size_n, -size_n,  0.0f, -1.0f,  0.0f,
     size_n, -size_n, -size_n,  0.0f, -1.0f,  0.0f,
     size_n, -size_n,  size_n,  0.0f, -1.0f,  0.0f,
     size_n, -size_n,  size_n,  0.0f, -1.0f,  0.0f,
    -size_n, -size_n,  size_n,  0.0f, -1.0f,  0.0f,
    -size_n, -size_n, -size_n,  0.0f, -1.0f,  0.0f,

    -size_n,  size_n, -size_n,  0.0f,  1.0f,  0.0f,
     size_n,  size_n, -size_n,  0.0f,  1.0f,  0.0f,
     size_n,  size_n,  size_n,  0.0f,  1.0f,  0.0f,
     size_n,  size_n,  size_n,  0.0f,  1.0f,  0.0f,
    -size_n,  size_n,  size_n,  0.0f,  1.0f,  0.0f,
    -size_n,  size_n, -size_n,  0.0f,  1.0f,  0.0f
};

  unsigned int vbo;
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo);
  
  glBindVertexArray(vao_);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &vbo);
}

void Cube::draw()
{
  glBindVertexArray(vao_);
  glDrawArrays(GL_TRIANGLES, 0, 36);
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