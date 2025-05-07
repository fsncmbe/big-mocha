#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <map>

#include "../module.hpp"
#include "../event/observer.hpp"
#include "../event/event.hpp"

namespace mocha {

class Log : public Observer
{
 friend class Module<Log>;
 public:
  enum class Setting {
    kLogKeys,
    kAssetLoad
  };

  void log(std::string message);
  void change_setting(Setting name, bool set);

  // Observer
  void onNotify(Event* e);

 private:
  std::map<Setting, bool> settings_map_ = 
  {
    {Setting::kLogKeys, false},
    {Setting::kAssetLoad, true}
  };

  Log() {};
  std::string eventTypeToString(Event* e);
};

}
#endif