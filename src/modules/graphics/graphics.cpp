#include "graphics.hpp"

namespace mocha {

void Graphics::draw(Drawable *drawable, glm::mat4 trans)
{
  glm::mat4 base(1.0f);
  base *= trans;
  // Base = glm::scale(base, drawable->scaler);
  current_shader_->setMat4("trans", base);
  // Sets translation uniform of the shader to the one used by the drawable
  drawable->draw();
}

void Graphics::init()
{

  std::string path = "media/shaders/";
  
  std::vector<std::string> shaders = {
      "default"
  };

  for (std::string s : shaders)
  {
      shader_map_[s] = new Shader();
      shader_map_[s]->load((path + s + ".vs").c_str(), (path + s + ".fs").c_str());
  }

  current_shader_ = shader_map_["default"];

  subject_.notifyObservers(new Event(Event::Type::kLogSuccess, "Graphics Init done"));
}

void Graphics::useShader()
{
  current_shader_->use();
}

Subject* Graphics::getSubject()
{
  return &subject_;
}

}
