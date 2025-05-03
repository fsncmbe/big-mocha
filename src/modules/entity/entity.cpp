#include "entity.hpp"

Entity *Entity::get(std::string uuid)
{   
    try 
    {
        return &(entity_map[uuid]);
    } catch(...)
    {
        entity_map[uuid] = Entity();
        return &(entity_map[uuid]);
    }
}

void Entity::del(std::string uuid)
{
    entity_map.erase(uuid);
}