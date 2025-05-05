#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "../entity/entity.hpp"

// Gives an entity desired properties, like physics, combat, animations,...
class Component
{
 public:
  // Gives component the entity its bound to
  Component(Entity* entity) : entity(entity) {};

  // Update all component features;
  virtual void update() = 0;
 protected:
  Entity* entity;
};

#endif