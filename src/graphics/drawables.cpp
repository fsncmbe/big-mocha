#include <mocha/graphics/drawables.hpp>

namespace mocha::graphics {

void Shader::use()
{
  glUseProgram(id_);
}

const char* Shader::load(const std::string& path)
{
  std::string v_code;
  std::string f_code;

  std::ifstream v_file;
  std::ifstream f_file;

  v_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  f_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    v_file.open(path + ".vs");
    f_file.open(path + ".fs");
    std::stringstream v_stream, f_stream;

    v_stream << v_file.rdbuf();
    f_stream << f_file.rdbuf();

    v_file.close();
    f_file.close();

    v_code = v_stream.str();
    f_code = f_stream.str();
  }
  catch (std::ifstream::failure& e)
  {
    return "BAD BIT";
  }

  const char* v_char = v_code.c_str();
  const char* f_char = f_code.c_str();

  int success_v, success_f, success_i;

  unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &v_char, NULL);
  glCompileShader(vertex);

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success_v);
  if(!success_v) {return "VERTEX SHADER COMPILE FAILURE";}

  unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &f_char, NULL);
  glCompileShader(fragment);

  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success_f);
  if(!success_f) {return "FRAGMENT SHADER COMPILE FAILURE";}

  id_ = glCreateProgram();
  glAttachShader(id_, vertex);
  glAttachShader(id_, fragment);
  glLinkProgram(id_);
  
  glGetProgramiv(id_, GL_LINK_STATUS, &success_i);
  if(!success_i) {return "SHADER LINK FAILURE";}

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  return "SUCCESS";
}

void Shader::setBool(const char *name, bool value)
{
  glUniform1i(glGetUniformLocation(id_, name), (int)value);
}

void Shader::setInt(const char *name, int value)
{
  glUniform1i(glGetUniformLocation(id_, name), value);
}

void Shader::setFloat(const char *name, float value)
{
  glUniform1f(glGetUniformLocation(id_, name), value);
}

void Shader::setVec2(const char *name, glm::vec2 value)
{
  glUniform2fv(glGetUniformLocation(id_, name), 1, &value[0]);
}

void Shader::setVec3(const char *name, glm::vec3 value)
{
  glUniform3fv(glGetUniformLocation(id_, name), 1, &value[0]);
}

void Shader::setVec4(const char *name, glm::vec4 value)
{
  glUniform4fv(glGetUniformLocation(id_, name), 1, &value[0]);
}

void Shader::setMat2(const char *name, glm::mat2 value)
{
  glUniformMatrix2fv(glGetUniformLocation(id_, name), 1, GL_FALSE, &value[0][0]);
}

void Shader::setMat3(const char *name, glm::mat3 value)
{
  glUniformMatrix3fv(glGetUniformLocation(id_, name), 1, GL_FALSE, &value[0][0]);
}

void Shader::setMat4(const char *name, glm::mat4 value)
{
  glUniformMatrix4fv(glGetUniformLocation(id_, name), 1, GL_FALSE, &value[0][0]);
}

Texture::Texture()
{
  width = 0;
  height = 0;
  internal_format = GL_RGB;
  image_format = GL_RGB;
  wrap_s = GL_REPEAT;
  wrap_r = GL_REPEAT;
  filter_min = GL_LINEAR;
  filter_max = GL_LINEAR;
  glGenTextures(1, &this->id_);
}

const char* Texture::load (const std::string& path)
{
  glBindTexture(GL_TEXTURE_2D, id_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_r);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_min);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_max);
  int width, height, nr_channels;
  unsigned char* data = stbi_load(path.c_str(), &width, &height, &nr_channels, 0);
  if (data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, image_format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    return "FAILED TO LOAD IMAGE WITH STB";
  }
  stbi_image_free(data);
  return "SUCCESS";
}

void Texture::use()
{
  glBindTexture(GL_TEXTURE_2D, id_);
}

}