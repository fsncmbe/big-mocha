#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <map>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

#include "gtypes.hpp"
#include "shader.hpp"
#include "drawable.hpp"


namespace mocha {
namespace graphics
{   

    // Shader stuff
    inline Shader* current_shader;
    // shadername = shader
    inline std::map<const char*, Shader> shader_map;

    // Draw a drawable object with transformation matrix for positioning
    void draw(Drawable* drawable, glm::mat4 trans);

    // Called before draw events to initialize shader etc.
    void init();
    void setShader(const char* id);
    void genShader(const char* path);
}
}

#endif