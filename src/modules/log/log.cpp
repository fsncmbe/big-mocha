#include "log.hpp"

namespace mocha {

void Log::log(std::string message)
{
  std::cout << message << "\n"; 
}

void Log::change_setting(Setting name, bool set)
{
  settings_map_[name] = set;
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
      if (eventTypeToString(e) != "")
        log("\033[1;31m" + eventTypeToString(e) + ":\033[0m" + e->getMessage());
  };
}

std::string Log::eventTypeToString(Event* e)
{
  if (settings_map_[Setting::kLogKeys])
  {
    switch(e->getType())
    {
      case Event::Type::kKeyDown:
        return "KEY_DOWN";
      case Event::Type::kKeyUp:
        return "KEY_UP";
    }
  }

  if (settings_map_[Setting::kAssetLoad] && e->getType() == Event::Type::kAssetLoaded)
  {
    return "ASSET_LOADED";
  }

  return "";
}

}