#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "glm/glm.hpp"

namespace mocha{
namespace graphics
{
    // Used as Supertype for all drawable objects
    class Drawable
    {
    public:
        virtual void draw() = 0;
        glm::vec3 scaler;
    };
}
}

#endif