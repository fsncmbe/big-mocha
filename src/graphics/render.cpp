#include <mocha/graphics/render.hpp>

namespace {

struct {
  mocha::graphics::Shader* current_shader;
  mocha::graphics::Camera* camera;
  unsigned int VAO;
} inst;

}

namespace mocha::graphics {

void setShader(Shader* shader)
{
  mocha::log(mocha::LogLevel::DEBUG, "SHADER SET");
  inst.current_shader = shader;
}

void updateShaders(float dt)
{
  if (inst.current_shader == nullptr)
  {
    mocha::log(mocha::LogLevel::ERROR, "NO SHADER LOADED");
    glfwTerminate();
  }

  inst.current_shader->setMat4("projection", inst.camera->getProjectionMatrix());
  inst.current_shader->setMat4("view", inst.camera->getViewMatrix());
}

void setCamera(Camera* camera)
{
  inst.camera = camera;
}

Camera* getCamera()
{
  return inst.camera;
}

void draw(Model &model_, glm::vec3 pos, glm::vec3 color)
{
  inst.current_shader->use();
  glm::mat4 model(1.0f);
  model = glm::translate(model, pos);
  
  inst.current_shader->setMat4("model", model);
  inst.current_shader->setMat4("projection", inst.camera->getProjectionMatrix());
  inst.current_shader->setMat4("view", inst.camera->getViewMatrix());

  glBindVertexArray(model_.VAO);
  glDrawArrays(GL_TRIANGLES, 0, model_.vertices_size);
  glBindVertexArray(0);
}

void update(float dt)
{
  inst.camera->update(dt);
}

void GraphicSys::update(float dt)
{
  for (int entity : mocha::ecs::view(1))
  {
    
  }
}

}