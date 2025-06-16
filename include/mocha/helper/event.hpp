#ifndef MOCHAEVENT_HPP
#define MOCHAEVENT_HPP

#include <iostream>
#include <vector>

// Everything very work in progress, return to later on 

namespace {
  struct {
    //std::vector<mocha::Observer*> observer_list_;
  } inst;
}

namespace mocha {

enum class EventType
{
  KeyDown,
  KeyUp
};

class Event
{
 public:
  virtual EventType type() const = 0;
};

/**
class KeyDownEvent : public IEvent
{
 public:
  KeyDownEvent(int key) : key(key) {};
  virtual EventType type() const{return EventType::KeyDown;}

  int key;
};

class KeyUpEvent : public IEvent
{
 public:
  KeyUpEvent(int key) : key(key) {};
  virtual EventType type() const{return EventType::KeyUp;}

  int key;
};
*/

// Class that wraps around an entity, for example InputObserver(Input)
/*
class ObserverWrapper
{
 public:
  virtual void onNotify(Event* e) = 0;
};
*/

//void pushEvent(Event* e);

//void addObserver();

//void removeObserver();

}

#endif