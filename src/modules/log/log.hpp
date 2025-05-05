#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>

#include "../module.hpp"
#include "../event/observer.hpp"
#include "../event/event.hpp"

// Singleton Module log
class Log : public Module, public Observer
{
 public:
  static Log* instance();
  
  void init();
  void log(std::string message);

  // Observer
  void onNotify(Event* e);
 private:
  Log() {};
  std::string eventTypeToString(Event* e);
};

#endif