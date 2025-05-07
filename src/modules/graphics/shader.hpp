#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "glad/glad.h"
#include "glm/glm.hpp"

namespace mocha {

class Shader
{
 public:
  Shader(int id = 0) : id_(id) {};
  void use();

  void setBool(const char* name, bool value);
  void setInt(const char* name, int value);
  void setFload(const char* name, float value);
  void setVec2(const char* name, glm::vec2 value);
  void setVec3(const char* name, glm::vec3 value);
  void setVec4(const char* name, glm::vec4 value);
  void setMat2(const char* name, glm::mat2 value);
  void setMat3(const char* name, glm::mat3 value);
  void setMat4(const char* name, glm::mat4 value);

 protected:
  unsigned int id_;
};

}

#endif