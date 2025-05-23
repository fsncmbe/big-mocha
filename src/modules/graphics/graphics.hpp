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

#include "gtypes.hpp"
#include "shader.hpp"
#include "drawable.hpp"
#include "body3d.hpp"
#include "camera.hpp"
#include "../module.hpp"
#include "../event/subject.hpp"
#include "../resource/resource.hpp"

namespace mocha {

class Graphics : public Observer
{
 friend class Module<Graphics>;
 public:
  void init();
  void readyRender();
  void draw(Drawable* drawable, glm::mat4 trans);
  void draw(Drawable* drawable, glm::vec3 pos);

  // Shader
  void useShader();
  Shader* getShader();

  // Subject
  Subject* getSubject();

  // Camera
  Camera* getCamera();

  // Observer
  void onNotify(Event* e);

  ~Graphics() {}
  
 private:
  Graphics() {}

  // Shader
  Shader* current_shader_;

  // Subject
  Subject subject_;

  // Camera
  Camera cam_;
};

}
#endif