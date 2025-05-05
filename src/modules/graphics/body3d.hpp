#ifndef BODY3D_HPP
#define BODY3D_HPP

#include "glad/glad.h"

#include "drawable.hpp"

namespace mocha {

class Cube : public Drawable
{
 public:
  Cube(glm::vec3 size);
  void draw();
};

class Ball : public Drawable
{
 public:
  Ball(float radius);
  void draw();
};

class Plane : public Drawable
{
 public:
  Plane(glm::vec2 size);
  void draw();
};

class Model : public Drawable
{
 public:
  Model();
  void draw();
};

}

#endif