#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <map>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

#include "../module.hpp"
#include "gtypes.hpp"
#include "shader.hpp"
#include "drawable.hpp"
#include "rectangle.hpp"

class Graphics : public Module
{
public:
    static Graphics* instance();
    void draw(Drawable* drawable, glm::mat4 trans);

    void init();
    //Shader
    void useShader();
    std::map<std::string, Shader*> shader_map;

private:
    Graphics() {};

    // Shader
    Shader* current_shader;
};

#endif