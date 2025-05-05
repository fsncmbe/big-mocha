#include "subject.hpp"

void Subject::notifyObservers(Event* e)
{
  for (Observer* o: observer_list)
  {
      o->onNotify(e);
  }
}

void Subject::addObserver(Observer* o)
{
  observer_list.push_back(o);
}

void Subject::removeObserver(Observer* o)
{
  for (
      std::vector<Observer*>::iterator iter = observer_list.begin(); 
      iter != observer_list.end();
      ++iter)
  {
      if(*iter == o)
      {
          observer_list.erase(iter);
          break;
      }
  }
}