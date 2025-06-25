#ifndef MOCHAENTITY_HPP
#define MOCHAENTITY_HPP

#include <iostream>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <bitset>

namespace mocha::ecs{

extern const int MAX_COMPONENTS = 2;

enum class ComponentTypes 
{
  kPosition,
  kModel,
};

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
  std::unordered_map<std::type_index, std::unordered_map<int, Component*>> components;

  std::vector<System*> systems;
} world;
}

int createEntity()
{
  world.entities.push_back(0);
  return world.entities.size()-1;
}

template<typename T>
void addComponent(int entity)
{

  auto type_id = std::type_index(typeid(T));
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

// Change View to take struct types, so that a sys does not need to specify a mask
std::vector<int> view(std::bitset<MAX_COMPONENTS> signature)
{
  std::vector<int> out;
  for (int i=0; i<world.entities.size(); i++)
  {
    if ((signature & world.entities[i]) == signature)
    {
      out.push_back(i);
    }
  }
  
  return out;
}

}
#endif