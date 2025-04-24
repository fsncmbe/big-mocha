#include "graphics.hpp"

void mocha::graphics::draw(Drawable *drawable, glm::mat4 trans)
{
    // Sets translation uniform of the shader to the one used by the drawable
    drawable->draw();
}

void mocha::graphics::init()
{
    // Load shaders
    std::string path = "../../../media/shaders/";

    // Shaders to load
    std::vector<std::string> shaders = {
        "default"
    };

    // Load all shaders into shader_map
    for (std::string s : shaders)
    {
        shader_map[s.c_str()] = Shader();
        shader_map[s.c_str()].load((path + s + ".vs").c_str(), (path + s + ".fs").c_str());
    }

    // Sets first shader of shaders to current shader and activates it
    current_shader = &shader_map[shaders[0].c_str()];
    current_shader->use();

    glEnable(GL_DEPTH_TEST);
}