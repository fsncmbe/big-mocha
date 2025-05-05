#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

namespace mocha {

class Event 
{
 public:
  enum class Type {
    kKeyDown,
    kKeyUp,
    kLogError,
    kLogSuccess
  };

  Event(Type type, std::string message) : type_(type), message_(message) {};

  Type getType();
  std::string getMessage();

 protected:
  Type        type_;
  std::string message_;
};

}
#endif