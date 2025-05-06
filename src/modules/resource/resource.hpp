#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

#include "../module.hpp"
#include "../graphics/shader.hpp"
#include "../event/subject.hpp"

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

  // Subject
  Subject subject_;
};

}
#endif