#include "log.hpp"

namespace mocha {

void Log::init()
{

}

void Log::log(std::string message)
{
  std::cout << message << "\n"; 
}

void Log::onNotify(Event* e)
{
  switch (e->getType())
  {
    //Differ for log events to change color later on
    case Event::Type::kLogError:
      log("\033[1;31mERROR:\033[0m" + e->getMessage());
      break;
    case Event::Type::kLogSuccess:
      log("\033[1;31mSUCCESS:\033[0m" + e->getMessage());
      break;
    default:
      log("\033[1;31m" + eventTypeToString(e) + ":\033[0m" + e->getMessage());
      break;
  };
}

std::string Log::eventTypeToString(Event* e)
{
  switch(e->getType())
  {
    case Event::Type::kKeyDown:
      return "KEY_DOWN";
    case Event::Type::kKeyUp:
      return "KEY_UP";
  }
  return "";
}

}