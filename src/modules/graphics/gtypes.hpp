#ifndef GRAPHICSTYPES_HPP
#define GRAPHICSTYPES_HPP

#include <glm/glm.hpp>

namespace mocha{
namespace graphics
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;
    };

    struct Texture
    {
        unsigned int id;
        const char* type;
    };
}
}

#endif