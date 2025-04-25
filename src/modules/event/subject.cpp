#include "subject.hpp"

void Subject::notifyObservers(Event* e)
{
    for (Observer* o: observer_list)
    {
        o->onNotify(e);
    }
}

void Subject::addObserver(Observer *o)
{
    observer_list.push_back(o);
}

void Subject::removeObserver(Observer *o)
{
    observer_list.erase(std::__find_if(observer_list.begin(), observer_list.end(), o));
}
