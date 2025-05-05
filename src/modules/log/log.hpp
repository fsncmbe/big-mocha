#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>

#include "../module.hpp"
#include "../event/observer.hpp"
#include "../event/event.hpp"

namespace mocha {

class Log : public Observer
{
 friend class Module<Log>;
 public:
  void init();
  void log(std::string message);

  // Observer
  void onNotify(Event* e);

 private:
  Log() {};
  std::string eventTypeToString(Event* e);
};

}
#endif