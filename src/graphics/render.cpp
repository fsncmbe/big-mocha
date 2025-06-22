#include <mocha/graphics/render.hpp>
#include "render.hpp"

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
  inst.current_shader->setVec3("view_pos", inst.camera->getPosition());
}

void genCubeData()
{
  unsigned int VBO;
  float vertices[24] = {
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
  };
  glGenVertexArrays(1, &inst.VAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(inst.VAO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);  
  glBindVertexArray(0);
}

void draw(Texture &tex, glm::vec2 pos, glm::vec2 size, float rotate, glm::vec3 color)
{
  inst.current_shader->use();
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(pos, 0.0f));

  // model rotations and translations
  model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); 
  model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); 
  model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

  model = glm::scale(model, glm::vec3(size, 1.0f));

  inst.current_shader->setMat4("model", model);
  inst.current_shader->setVec3("spriteColor", color);
  inst.current_shader->setMat4("projection", glm::ortho(0.0f, 1920.0f, 
        1080.0f, 0.0f, -1.0f, 1.0f));
  inst.current_shader->setInt("image", 0);

  glActiveTexture(GL_TEXTURE0);
  tex.use();

  glBindVertexArray(inst.VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
}

void draw(Model &model_, glm::vec3 pos, glm::vec3 color)
{
  inst.current_shader->use();
  glm::mat4 model(1.0f);
  model = glm::translate(model, pos);
  
  inst.current_shader->setMat4("projection", inst.camera->getProjectionMatrix());
  inst.current_shader->setMat4("view", inst.camera->getViewMatrix());

  glBindVertexArray(model_

}
}