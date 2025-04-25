#include "graphics.hpp"

void Graphics::draw(Drawable *drawable, glm::mat4 trans)
{
    current_shader->setMat4("trans", trans);
    // Sets translation uniform of the shader to the one used by the drawable
    drawable->draw();
}
Graphics* Graphics::instance()
{
    static Graphics* instance = new Graphics();
    return instance;
}

void Graphics::init()
{
    // Load shaders
    std::string path = "media/shaders/";

    // Shaders to load
    std::vector<std::string> shaders = {
        "default"
    };

    // Load all shaders into shader_map
    for (std::string s : shaders)
    {
        shader_map[s] = new Shader();
        shader_map[s]->load((path + s + ".vs").c_str(), (path + s + ".fs").c_str());
    }

    // Sets first shader of shaders to current shader and activates it
    current_shader = shader_map["default"];
}

void Graphics::useShader()
{
    current_shader->use();
}
