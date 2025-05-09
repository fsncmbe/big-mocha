#ifndef FONT_HPP
#define FONT_HPP

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "drawable.hpp"

namespace mocha {

class Font : public Drawable
{
 public:
  void draw();

 private:
};

}

#endif