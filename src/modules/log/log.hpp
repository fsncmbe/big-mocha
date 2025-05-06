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
  void log(std::string message);
  void change_setting(std::string name, bool set);

  // Observer
  void onNotify(Event* e);

 private:
  std::map<std::string, bool> settings_map_ = 
  {
    {"LogKeys", false},
    {"AssetLoad", true}
  };

  Log() {};
  std::string eventTypeToString(Event* e);
};

}
#endif