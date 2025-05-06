#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>

#include "event.hpp"
#include "observer.hpp"

namespace mocha {

class Subject
{
 public:
  Subject() {};
  void notifyObservers(Event* e);
  Subject* addObserver(Observer* o);
  void removeObserver(Observer* o);
  ~Subject() {
    observer_list_.clear();
  };
 private:
  std::vector<Observer*> observer_list_;
};

}

#endif