#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "event.hpp"

template <typename T>
class Observer
{
public:
    virtual void onNotify(Event<T>* e) = 0;

private:
};


#endif