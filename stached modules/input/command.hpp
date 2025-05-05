#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../entity/entity.hpp"

// Interface for commands
class Command
{
 public:
  Command(Entity* entity) : entity(entity) {};
  // Executes a command on given Entity
  virtual void execute() = 0;
  
 protected:
  Entity* entity;
};

#endif