#include "graphics.hpp"

namespace mocha {

void Graphics::init()
{
  std::string path = "media/shaders/";
  
  std::string shaders[] = {
      "default"
  };
  
  for (std::string s : shaders)
  {
      shader_map_[s] = Shader();
      shader_map_[s].load((path + s + ".vs").c_str(), (path + s + ".fs").c_str());
  }

  current_shader_ = &shader_map_["default"];
  subject_.notifyObservers(new Event(Event::Type::kLogSuccess, "Graphics init done"));
}

void Graphics::readyRender()
{
  useShader();
  getShader()->setMat4("projection", cam_.getProjectionMatrix());
  getShader()->setMat4("view", cam_.getViewMatrix());
}

void Graphics::draw(Drawable *drawable, glm::mat4 trans)
{
  glm::mat4 base(1.0f);
  base *= trans;
  current_shader_->setMat4("trans", base);

  drawable->draw();
}

void Graphics::draw(Drawable *drawable, glm::vec3 pos)
{
  glm::mat4 base(1.0f);
  base = glm::translate(base, pos);
  current_shader_->setMat4("trans", base);

  drawable->draw();
}

void Graphics::useShader()
{
  current_shader_->use();
}

Shader *Graphics::getShader()
{
  return current_shader_;
}

Subject* Graphics::getSubject()
{
  return &subject_;
}

Camera* Graphics::getCamera()
{
  return &cam_;
}

void Graphics::onNotify(Event* e)
{
  switch(e->getType())
  {
    case Event::Type::kWindowSizeChange: 
    {
      glm::vec3 tvec = e->getVec3();
      cam_.processProjectionChange({tvec.x, tvec.y});
      return;
    }
    default :
      return;
  }
}
}
