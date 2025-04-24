#include "graphics.hpp"

void mocha::graphics::draw(Drawable *drawable, glm::mat4 trans)
{
    current_shader->setMat4("trans", trans);
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
    for (std::string s : shaders)
    {
        std::cout << (path + s + ".vs").c_str() << "\n";
        shader_map[s.c_str()] = Shader();
        shader_map[s.c_str()].load((path + s + ".vs").c_str(), (path + s + ".fs").c_str());
    }
    current_shader = &shader_map[shaders[0].c_str()];
    current_shader->use();
}