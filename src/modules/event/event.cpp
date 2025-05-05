#include "event.hpp"

Event::Type Event::getType()
{
  return type;
}

std::string Event::getMessage()
{
  return message;
}
