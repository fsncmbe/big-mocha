#include "event.hpp"

Event::EventType Event::getType()
{
    return type;
}

std::string Event::getMessage()
{
    return message;
}
