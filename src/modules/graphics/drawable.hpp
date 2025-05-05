#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "glm/glm.hpp"

namespace mocha {

class Drawable
{
 public:
  glm::vec3 scaler_;
  virtual void draw() = 0;
 protected:
  unsigned int vao_;
};

}

#endif