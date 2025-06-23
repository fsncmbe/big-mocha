#ifndef MOCHADRAWABLES_HPP
#define MOCHADRAWABLES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <stb/stb_image.h>

#include <mocha/helper/resource.hpp>

namespace mocha::graphics {

class Shader : public mocha::resource::IResource
{
 public:
  Shader() {};

  const char* load(const std::string& path);
  
  void use();

  void setBool(const char* name, bool value);
  void setInt(const char* name, int value);
  void setFloat(const char* name, float value);
  void setVec2(const char* name, glm::vec2 value);
  void setVec3(const char* name, glm::vec3 value);
  void setVec4(const char* name, glm::vec4 value);
  void setMat2(const char* name, glm::mat2 value);
  void setMat3(const char* name, glm::mat3 value);
  void setMat4(const char* name, glm::mat4 value);

 protected:
  unsigned int id_;
};

class Texture : public mocha::resource::IResource
{
 public:
  Texture();

  const char* load (const std::string& path);

  void use();

  unsigned int width, height;
  unsigned int internal_format, image_format;

  unsigned int wrap_s, wrap_r;
  unsigned int filter_min, filter_max;


 private:
  unsigned int id_;
};

class Model : public mocha::resource::IResource
{
 public:
  const char* load (const std::string& path);
  unsigned int VAO;
  unsigned int vertices_size;

 private:
  bool loadModel(std::vector<glm::vec3> &vertices);
};

}

#endif