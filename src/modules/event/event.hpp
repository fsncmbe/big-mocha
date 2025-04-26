#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

// Event class
template<typename T>
class Event
{
public:
    virtual T getData();
protected:
    T data;
};


#endif