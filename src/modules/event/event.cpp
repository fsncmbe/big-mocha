#include "event.hpp"

namespace mocha {

Event::Type Event::getType()
{
  return type_;
}

std::string Event::getMessage()
{
  return message_;
}

int Event::getNum()
{
  return num_;
}

glm::vec3 Event::getVec3()
{
  return vec3_;
}
}