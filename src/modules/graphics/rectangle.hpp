#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

#include "drawable.hpp"
#include "glad/glad.h"

class Rectangle : public Drawable
{
 public:
  // Baseline rectangle init, no effects
  Rectangle(glm::vec2 size);

  // Draw call
  void draw();
 private:
  unsigned int VAO;
};



#endif