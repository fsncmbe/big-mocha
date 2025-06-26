#ifndef MOCHAENTITY_HPP
#define MOCHAENTITY_HPP

#include <mocha/helper/log.hpp>

#include <iostream>
#include <typeindex>
#include <map>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <algorithm>

namespace mocha::ecs{

inline const std::size_t MAX_COMPONENTS = 2;

// Component Class, every Component needs to implement it
class Component
{
};

class System 
{
 public:
  virtual void update(float dt) = 0;
  virtual void notifyComponents() = 0;
  std::bitset<MAX_COMPONENTS> signature;

};

struct Position : Component{
  float x, y, z;
};

namespace {
struct {
  // Holds all entities and their bitmask, their id is equal to position in vector
  std::vector<std::bitset<MAX_COMPONENTS>> entities;

  // Holds all components for every entity categorized by the component type
  std::map<std::type_index, std::unordered_map<int, Component*>> components;

  std::vector<System*> systems;
} world;


template<typename T>
int getComponentBit()
{
  int i = 0;
  for (auto it = world.components.begin(); it != world.components.end(); ++it)
  {
    if (it->first == std::type_index(typeid(T)))
    {
      return i;
    }
    i++;
  }

  return -1;
}
}

int createEntity()
{
  world.entities.push_back(0);
  return world.entities.size()-1;
}

std::bitset<MAX_COMPONENTS> getEntity(int e)
{
  return world.entities[e];
}

template<typename T>
void addComponent(int entity)
{
  auto type_id = std::type_index(typeid(T));
  
  int comp_bit = getComponentBit<T>();

  if (comp_bit == -1)
  {
    world.components[type_id];
    comp_bit = getComponentBit<T>();
  }

  world.entities[entity].set(comp_bit);

  world.components[type_id][entity] = new T();
}

template<typename T>
T* getComponent(int entity)
{
  auto type_id = std::type_index(typeid(T));
  return world.components[type_id][entity];
}

// Big update call for all systems
void update(float dt)
{
  for (System* s : world.systems)
  {
    s->update(dt);
  }
}


// TODO: OPTIMIZATION, CURRENTLY REALLY ROUGH EXECUTION
template<typename... T>
std::vector<int> view()
{
  std::bitset<MAX_COMPONENTS> mask;
  std::vector<int> out;

  // Check if component has been used
  bool noBit = false;
  (((getComponentBit<T>() == -1) ? noBit = true : false), ...);

  if(noBit){return out;}
  
  // If they are continue setting mask
  (mask.set(getComponentBit<T>()), ...);
  for (int i=0; i<world.entities.size(); i++)
  {
    if ((world.entities[i] & mask) == mask)
    {
      out.push_back(i);
    }
  }
  return out;
}

}
#endif