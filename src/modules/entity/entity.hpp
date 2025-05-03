#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include <string>

// Entity class for all interactable things like player, npc, menu, doors,...
class Entity
{
public:

    // Returns entity if it exists, else creates new
    static Entity* get(std::string uuid);

    // Deletes given entity
    static void del(std::string uuid);

private:
    // Private constructor, only use get()
    Entity(){};
    
    // Every entity is saved in this
    static std::map<std::string, Entity> entity_map;
};

#endif