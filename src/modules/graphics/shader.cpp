#include "shader.hpp"

namespace mocha {

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

}