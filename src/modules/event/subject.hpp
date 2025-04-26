#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>

#include "event.hpp"
#include "observer.hpp"

// Send events to bound observers
template <typename T>
class Subject
{
public:
    void notifyObservers(Event<T>* e);
    void addObserver(Observer<T>* o);
    void removeObserver(Observer<T>* o);
private:
    std::vector<Observer<T>*> observer_list;
};

#endif