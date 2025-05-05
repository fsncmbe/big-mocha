#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "event.hpp"

namespace mocha {

class Observer
{
 public:
  virtual void onNotify(Event* e) = 0;
};

}
#endif