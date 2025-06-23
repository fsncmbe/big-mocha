#ifndef MOCHAENTITY_HPP
#define MOCHAENTITY_HPP

#include <iostream>
#include <typeindex>
#include <map>
#include <vector>

namespace mocha::ecs{

// Component class that holds things for an entity like model, position,...
class IComponent
{
 public:
  virtual void create() = 0;
 private:
};

class ISystem
{
 public:
  virtual void update(float dt) = 0;
};

class Entity
{
 public:
  int id;
  std::vector<IComponent*> components;
 private:
};

namespace {
struct {
  std::vector<mocha::ecs::ISystem*> systems;
  std::vector<Entity*> entities;
} inst;
}

void update(float dt)
{
  for (auto& sys : inst.systems)
  {
    sys->update(dt);
  }
};

Entity* addEntity()
{
  inst.entities.push_back(new Entity());
  return inst.entities.back();
}

void addComponent(Entity* entity, IComponent* component)
{
  entity->components.push_back(component);
}

}
#endif