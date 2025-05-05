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

}