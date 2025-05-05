#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

// Event class
class Event
{
 public:
  enum class Type {
      KEY_DOWN,
      KEY_UP,
      LOGERROR,
      LOGSUCCESS
  };
  Event(Type type, std::string message) : type(type), message(message) {};

  Type getType();
  std::string getMessage();
 protected:
  Type type;
  std::string message;
};


#endif