#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <map>
#include <vector>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

#include "gtypes.hpp"
#include "mesh.hpp"
#include "drawable.hpp"

namespace mocha {
namespace graphics
{   
    // Big render call, renders all
    void render();

    // Draw a drawable object
    void draw(Drawable* drawable);

    void setShader();
}
}

#endif