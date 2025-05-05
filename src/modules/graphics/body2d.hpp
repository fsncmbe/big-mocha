#ifndef BODY2D_HPP
#define BODY2D_HPP

#include "glad/glad.h"

#include "drawable.hpp"

namespace mocha {

class Rectangle : public Drawable
{
  public:
  Rectangle(glm::vec2 size);
  void draw();
};

}

#endif