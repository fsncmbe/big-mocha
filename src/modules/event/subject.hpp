#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>

#include "event.hpp"
#include "observer.hpp"

// Send events to bound observers
class Subject
{
public:
    void notifyObservers(Event* e);
    void addObserver(Observer* o);
    void removeObserver(Observer* o);
private:
    std::vector<Observer*> observer_list;
};

#endif