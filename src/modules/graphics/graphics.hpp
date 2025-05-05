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
#include "body3d.hpp"
#include "../event/subject.hpp"

namespace mocha {

class Graphics
{
 friend class Module<Graphics>;
 public:
  void init();
  void draw(Drawable* drawable, glm::mat4 trans);

  // Shader
  void useShader();

  // Subject
  Subject* getSubject();

 private:
  Graphics() {};

  // Shader
  std::map<std::string, Shader*> shader_map_;
  Shader* current_shader_; 

  // Subject
  Subject subject_;
};

}
#endif