#ifndef GRAPHICSTYPES_HPP
#define GRAPHICSTYPES_HPP

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "stb/stb_image.h"

namespace mocha{
namespace graphics
{
    class Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;
    };

    class Texture
    {
        unsigned int id;
        const char* type;
    };

    void loadTexture(const char* path);
}
}

#endif