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

int Event::getInt()
{
  return num_int_;
}

float Event::getFloat()
{
  return num_float_;
}

glm::vec3 Event::getVec3()
{
  return vec3_;
}
}