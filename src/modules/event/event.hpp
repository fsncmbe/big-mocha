#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

#include "glm/glm.hpp"
#include "../module.hpp"

namespace mocha {

class Event 
{
 public:
  enum class Type {
    kKeyDown,
    kKeyUp,
    kLogError,
    kLogSuccess,
    kWindowSizeChange
  };

  Event(Type type, std::string message = "", int num = 0, glm::vec3 vec3 = {0,0,0}) 
      : type_(type), message_(message), num_(num), vec3_(vec3) {};

  Type getType();
  std::string getMessage();
  int getNum();
  glm::vec3 getVec3();

 protected:
  Type        type_;
  std::string message_;
  int         num_;
  glm::vec3   vec3_;
};

}
#endif