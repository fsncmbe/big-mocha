#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

#include "stb/stb_image.h"

#include "../module.hpp"
#include "../graphics/shader.hpp"
#include "../graphics/body3d.hpp"
#include "../event/subject.hpp"
#include "../graphics/font.hpp"
#include "../graphics/gtypes.hpp"

namespace mocha {

class Resource 
{
 friend class Module<Resource>;
 public:
  void init();

  template <typename T>
  void load(std::string path);

  template <typename T>
  T* get(std::string path);

  template <typename T>
  void del(std::string path);

  // Subject
  Subject* getSubject() {return &subject_;}

 private:
  Resource(){};
  std::map<std::string, Shader> shader_map_;
  void loadShader(std::string path);
  void checkShader(unsigned int id, std::string type);

  std::map<std::string, Model>  model_map_;
  void loadModel(std::string path);
  void checkModel(Model* model);

  std::map<std::string, Font> font_map_;
  void loadFont(std::string path);
  void checkFont(Font* font);

  std::map<std::string, Texture> texture_map_;
  void loadTexture(std::string path);

  // Subject
  Subject subject_;
};

}
#endif