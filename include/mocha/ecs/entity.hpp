#ifndef MOCHAENTITY_HPP
#define MOCHAENTITY_HPP

#include <iostream>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <bitset>

namespace mocha::ecs{

enum class ComponentTypes 
{
  kPosition,
  kModel,
  kSize
};

class Component
{
};

struct Position {
  float x, y, z;
};

namespace {
struct {
  // Holds all entities and their bitmask, their id is equal to position in vector
  std::vector<std::bitset<static_cast<int>(ComponentTypes::kSize)>> entities;

  // Holds all components for every entity categorized by the component type
  std::unordered_map<std::type_index, std::unordered_map<int, Component*>> components;
} world;
}

int createEntity()
{
  world.entities.push_back(0);
}

template<typename T, typename... Args>
void addComponent(int entity, Args&&... args)
{
  auto type_id = std::type_index(typeid(T));

  world.components[type_id][entity] = T(std::forward<Args>(args)...);
}

}
#endif