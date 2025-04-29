#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

// Event class
class Event
{
public:
    enum class EventType {
        KEY_DOWN,
        KEY_UP,
        LOGERROR,
        LOGSUCCESS
    };
    Event(EventType type, std::string message) : type(type), message(message) {};

    EventType getType();
    std::string getMessage();
protected:
    EventType type;
    std::string message;
};


#endif