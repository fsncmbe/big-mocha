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
    kWindowSizeChange,
    kAssetLoaded
  };

  Event(Type type, std::string message = "", int num_int = 0, float num_float = 0.0f, glm::vec3 vec3 = {0,0,0}) 
      : type_(type), message_(message), num_int_(num_int), num_float_(num_float), vec3_(vec3) {};

  Event(Type type, int num_int) : num_int_(num_int) {};

  Event(Type type, float num_float) : num_float_(num_float) {};

  Event(Type type, glm::vec3 vec3) : vec3_(vec3) {};

  Type getType();
  std::string getMessage();
  int getInt();
  float getFloat();
  glm::vec3 getVec3();

 protected:
  Type        type_;
  std::string message_;
  int         num_int_;
  float       num_float_;
  glm::vec3   vec3_;
};

}
#endif