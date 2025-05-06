#include "subject.hpp"

namespace mocha {

void Subject::notifyObservers(Event* e)
{
  for (Observer* o: observer_list_)
  {
      o->onNotify(e);
  }
}

Subject* Subject::addObserver(Observer* o)
{
  observer_list_.push_back(o);
  return this;
}

void Subject::removeObserver(Observer* o)
{
  for (
    std::vector<Observer*>::iterator iter = observer_list_.begin(); 
    iter != observer_list_.end();
    ++iter)
  {
    if(*iter == o)
    {
      observer_list_.erase(iter);
      break;
    }
  }
}

}