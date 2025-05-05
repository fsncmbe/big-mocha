#include "shader.hpp"

namespace mocha {

Shader::Shader()
{
}

void Shader::load(const char *vertex_path, const char *fragment_path)
{
  // 1. retrieve source code from filePath
  std::string vertex_code;
  std::string fragment_code;
  std::ifstream v_shader_file;
  std::ifstream f_shader_file;

  v_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  f_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  
  try
  {
      v_shader_file.open(vertex_path);
      f_shader_file.open(fragment_path);
      std::stringstream v_shader_stream, f_shader_stream;

      v_shader_stream << v_shader_file.rdbuf();
      f_shader_stream << f_shader_file.rdbuf();

      v_shader_file.close();
      f_shader_file.close();

      vertex_code = v_shader_stream.str();
      fragment_code = f_shader_stream.str();
  }
  catch(std::ifstream::failure& e)
  {
      std::cerr << e.what() << '\n';
  }
  
  const char* v_shader_code = vertex_code.c_str();
  const char* f_shader_code = fragment_code.c_str();

  unsigned int vertex, fragment;

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &v_shader_code, NULL);
  glCompileShader(vertex);
  checkCompileErrors(vertex, "VERTEX");

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &f_shader_code, NULL);
  glCompileShader(fragment);
  checkCompileErrors(fragment, "FRAGMENT");

  id_ = glCreateProgram();
  glAttachShader(id_, vertex);
  glAttachShader(id_, fragment);
  glLinkProgram(id_);
  checkCompileErrors(id_, "PROGRAM");

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::use()
{
  glUseProgram(id_);
}

void Shader::setBool(const char *name, bool value)
{
  glUniform1i(glGetUniformLocation(id_, name), (int)value);
}

void Shader::setInt(const char *name, int value)
{
  glUniform1i(glGetUniformLocation(id_, name), value);
}

void Shader::setFload(const char *name, float value)
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

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
  int success;
  char infoLog[1024];
  if (type != "PROGRAM")
  {
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
      if (!success)
      {
          glGetShaderInfoLog(shader, 1024, NULL, infoLog);
          std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
      }
  }
  else
  {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);
      if (!success)
      {
          glGetProgramInfoLog(shader, 1024, NULL, infoLog);
          std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
      }
  }
}

}