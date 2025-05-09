#include "resource.hpp"

namespace mocha {

template <typename T>
void Resource::load(std::string path)
{
    if (typeid(T) == typeid(Shader))
      loadShader(path);
    if (typeid(T) == typeid(Model))
      loadModel(path);
    if (typeid(T) == typeid(Texture))
      loadTexture(path);
    subject_.notifyObservers(new Event(Event::Type::kAssetLoaded, path));
}

template <typename T>
T* Resource::get(std::string path)
{
  if (typeid(T) == typeid(Shader))
  {
    if (shader_map_.count(path))
      return &(shader_map_[path]);
  }
  if (typeid(T) == typeid(Model))
  {
    if (model_map_.count(path))
      return &(model_map_[path]);
  }
  if (typeid(T) == typeid(Texture))
  {
    if (texture_map_.count(path))
      return &(texture_map_[path]);
  }
  return NULL;
}

template <typename T>
void Resource::del(std::string path)
{
  if (typeid(T) == typeid(Shader))
  {
    if (shader_map_.count(path))
      shader_map_.erase(path);
  }
  if (typeid(T) == typeid(Model))
  {
    if (model_map_.count(path))
      model_map_.erase(path);
  }
  if (typeid(T) == typeid(Texture))
  {
    if (texture_map_.count(path))
      texture_map_.erase(path);
  }
}

void Resource::loadShader(std::string path)
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
  catch(std::ifstream::failure& e)
  {
    subject_.notifyObservers(new Event(Event::Type::kLogError, "BAD BIT"));
  }

  unsigned int vertex, fragment;

  const char* v_code_c = v_code.c_str();
  const char* f_code_c = f_code.c_str();

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &v_code_c, NULL);
  glCompileShader(vertex);
  checkShader(vertex, "VERTEX");

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &f_code_c, NULL);
  glCompileShader(fragment);
  checkShader(fragment, "FRAGMENT");

  int id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);
  glLinkProgram(id);
  checkShader(id, "PROGRAM");

  shader_map_[path] = Shader(id);

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Resource::checkShader(unsigned int id, std::string type)
{
  int success;
  char infoLog[1024];
  if (type != "PROGRAM")
  {
      glGetShaderiv(id, GL_COMPILE_STATUS, &success);
      if (!success)
      {
          glGetShaderInfoLog(id, 1024, NULL, infoLog);
          subject_.notifyObservers(new Event(Event::Type::kLogError, "SHADER_COMPILATION_ERROR"));
      }
  }
  else
  {
      glGetProgramiv(id, GL_LINK_STATUS, &success);
      if (!success)
      {
          glGetProgramInfoLog(id, 1024, NULL, infoLog);
          subject_.notifyObservers(new Event(Event::Type::kLogError, "SHADER_LINK_ERROR"));
      }
  }
}

void Resource::loadModel(std::string path)
{
  
}

void Resource::loadFont(std::string path)
{

}

void Resource::loadTexture(std::string path)
{
  unsigned int texture;

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width, height, nr_channels;
  stbi_set_flip_vertically_on_load(true);

  unsigned char* data = stbi_load(path.c_str(), &width, &height, &nr_channels, 0);
  if (data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_INT, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else 
  {
    subject_.notifyObservers(new Event(Event::Type::kLogError, "Failed to load: " + path));
  }
  stbi_image_free(data);

  texture_map_[path] = {texture};
}

template void Resource::load<Shader>(std::string path);
template Shader* Resource::get<Shader>(std::string path);

template void Resource::load<Model>(std::string path);
template Model* Resource::get<Model>(std::string path);

template void Resource::load<Font>(std::string path);
template Font* Resource::get<Font>(std::string path);

template void Resource::load<Texture>(std::string path);
template Texture* Resource::get<Texture>(std::string path);

}