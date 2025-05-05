#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "event.hpp"

class Observer
{
 public:
  virtual void onNotify(Event* e) = 0;
  
 private:
};

#endif