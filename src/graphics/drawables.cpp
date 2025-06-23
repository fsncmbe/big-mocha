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

const char* Model::load (const std::string& path)
{
  std::vector<unsigned int> vertex_indices, uv_indices, normal_indices;

  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> vertices_;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals;

  FILE* file = fopen(path.c_str(), "r");
  if (file == NULL)
  {
    return "File not openable, maybe non existent!";
  }

  while (true)
  {
    char line_head[128];
    int res = fscanf(file, "%s", line_head);
    if (res == EOF)
      break;
    if (strcmp(line_head, "v") == 0)
    {
      glm::vec3 vertex;
      fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
      vertices.push_back(vertex);
    } 
    else if (strcmp(line_head, "vt") == 0)
    {
      glm::vec2 uv;
      fscanf(file, "%f %f\n", &uv.x, &uv.y );
      uvs.push_back(uv);
    }
    else if (strcmp(line_head, "vn") == 0 )
    {
      glm::vec3 normal;
      fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
      normals.push_back(normal);
    }
    else if (strcmp(line_head, "f") == 0)
    {
      std::string vertex1, vertex2, vertex3;
      unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
      int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
      if (matches != 9){
          return "Failure while parsing";
      }
      vertex_indices.push_back(vertexIndex[0]);
      vertex_indices.push_back(vertexIndex[1]);
      vertex_indices.push_back(vertexIndex[2]);
      uv_indices    .push_back(uvIndex[0]);
      uv_indices    .push_back(uvIndex[1]);
      uv_indices    .push_back(uvIndex[2]);
      normal_indices.push_back(normalIndex[0]);
      normal_indices.push_back(normalIndex[1]);
      normal_indices.push_back(normalIndex[2]);
    }
  }

  for (int i=0; i<vertex_indices.size(); i++)
  {
    unsigned int vertex_index = vertex_indices[i];
    glm::vec3 vertex = vertices[vertex_index-1];
    vertices_.push_back(vertex);
  }

  /**
  for (int i=0; i<uv_indices.size(); i++)
  {
    unsigned int uv_index = uv_indices[i];
    glm::vec2 uv = uvs[uv_index-1];
    uvs_.push_back(uv);
  }

  for (int i=0; i<normal_indices.size(); i++)
  {
    unsigned int normal_index = normal_indices[i];
    glm::vec3 normal = normals[normal_index-1];
    normals_.push_back(normal);
  }
  */

  vertices_size = vertices_.size();

  if (loadModel(vertices_))
  {
    return "SUCCESS";
  }
  return "MODEL LOADING";
}

bool Model::loadModel(std::vector<glm::vec3> &vertices)
{ 
  GLuint VBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glBindVertexArray(0);
  return true;
}

}