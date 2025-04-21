#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <map>
#include <vector>

// Resource manager
namespace ResourceManager
{   

    // Interface used for ResourceManager Map to manage each filetype
    struct File
    {
    public:
        virtual void load(const char* path) = 0;
    };

    std::map<const char*, File*> resource_map;

    // Get File reference to use
    File* get(const char* id)
    {
        resource_map[id]->load(id);
        return resource_map[id];
    }

    // Load a file depending on file ending IMPLEMENT!!
    void loadFile(const char* id)
    {
        resource_map[id]->load(id);
    }

    // Loads a bunch of files
    void loadFiles(std::vector<const char*> ids)
    {
        for(const char* id: ids)
        {
            loadFile(id);
        }
    }

    // Load a whole folder
    void loadFolder(const char* folder_id)
    {
        // In construction, currently not needed 
    }

    // Unloads a file   REWRITE
    void unloadFile(const char* id)
    {
        if (!resource_map.count(id))
        {
            return;
        }
    }

    // Unloads a bunch of files REWRITE
    void unloadFiles(std::vector<const char*> ids)
    {
        for(const char* id: ids)
        {
            unloadFile(id);
        }
    }
}

#endif