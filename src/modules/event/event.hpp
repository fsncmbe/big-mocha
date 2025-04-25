#ifndef EVENT_HPP
#define EVENT_HPP

// Event interface class, use to create other Events
class Event
{
public:
    enum EventType
    {
        KEYBOARD_INPUT
    };
    EventType type;
    virtual void handle() = 0;
private:
};

class KeyboardEvent : public Event
{
public:
    KeyboardEvent(int input);
    void handle();
private:
    int pressed_key;
};

#endif