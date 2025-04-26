#include "subject.hpp"

template <typename T>
inline void Subject<T>::notifyObservers(Event<T>* e)
{
    for (Observer* o: observer_list)
    {
        o->onNotify(e);
    }
}

template <typename T>
void Subject<T>::addObserver(Observer<T> *o)
{
    observer_list.push_back(o);
}

template <typename T>
void Subject<T>::removeObserver(Observer<T> *o)
{
    observer_list.erase(std::__find_if(observer_list.begin(), observer_list.end(), o));
}
