#ifndef GRAPHICSTYPES_HPP
#define GRAPHICSTYPES_HPP

#include <iostream>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "stb/stb_image.h"

namespace mocha {

struct Vertex
{
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 tex_coords;
};

struct Texture
{
  unsigned int id;
};

}
#endif