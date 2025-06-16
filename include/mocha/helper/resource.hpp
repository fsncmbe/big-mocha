#ifndef MOCHARESOURCE_HPP
#define MOCHARESOURCE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <typeindex>

#include <mocha/helper/log.hpp>

namespace mocha::resource {

class IResource
{
  public:
  virtual const char* load(const std::string& path) = 0;
};

class DummyResource : public IResource
{
 public:
  const char* load(const std::string& path)
  {
    return "SUCCESS";
  }
};

class Text : public IResource
{
 public:
  const char* load(const std::string& path);
  std::vector<std::string> lines;
};

class DummyText : public Text
{
  const char* load(const std::string& path) override {return "null";};
};

// Private namespace 
namespace {
struct ResourceEntry {
  mocha::resource::IResource* entry;
  std::string path;
};

struct {
  std::map<std::type_index, std::vector<ResourceEntry>> resource_map;
  std::map<std::type_index, std::vector<int>> id_counts;
} inst;

}

// loads and returns int, for future usage like a wrapper when things take longer to load
template<typename T>
int load(const std::string& path)
{
  static_assert(std::is_base_of<IResource, T>::value, "T must inherit from Resource");
  auto type_id = std::type_index(typeid(T));

  auto it = std::find_if(inst.resource_map[type_id].begin(), 
                        inst.resource_map[type_id].end(), 
                        [path](const ResourceEntry& s)
  {
    return s.path == path;
  });

  if (it != inst.resource_map[type_id].end())
  {
    int id = (int)std::distance(inst.resource_map[type_id].begin(), it);
    log(LogLevel::DEBUG, "Already Loaded: " + path + " at " + std::to_string(id));
    return id;
  }

  // If not loaded create new
  T* entry = new T();
  const char* s = entry->load(path);

  if (std::string(s) != "SUCCESS")
  {
    log(LogLevel::ERROR, "Failed to load: " + path + ". CAUSE: " + s);
    return 0;
  }

  int id = inst.id_counts[type_id].size();

  // If there are empty places to fill, else just push onto the back
  if (id != 0)
  {
    id = inst.id_counts[type_id].back();
    inst.id_counts[type_id].pop_back();
    inst.resource_map[type_id][id] = {entry, path};
    log(LogLevel::DEBUG, "Loaded: " + path + " at " + std::to_string(id));
    return id;
  } else {
    id = inst.resource_map[type_id].size();
    inst.resource_map[type_id].push_back({entry, path});
    log(LogLevel::DEBUG, "Loaded: " + path + " at " + std::to_string(id));
    return id;
  }
}

template<typename T>
T* get(int id)
{
  static_assert(std::is_base_of<IResource, T>::value, "T must inherit from Resource");
  auto type_id = std::type_index(typeid(T));

  if(inst.resource_map[type_id].size() == 0)
  {
    log(LogLevel::ERROR, "No Resource of that type saved");
    return nullptr;
  }

  if(id >= inst.resource_map[type_id].size()) 
  {
    log(LogLevel::ERROR, "Resource id out of bounds");
    return nullptr;
  }

  ResourceEntry* entry = &(inst.resource_map[type_id][id]);

  std::string returnstr = "Got: " + entry->path;
  log(LogLevel::DEBUG, returnstr);

  return (T*)entry->entry;
}

template<typename T>
void del(int id)
{
  auto type_id = std::type_index(typeid(T));
  delete inst.resource_map[type_id][id].entry;
  inst.resource_map[type_id][id].entry = nullptr;
  inst.id_counts[type_id].push_back(id);
}

template<typename T>
void logFilesLoaded()
{
  auto type_id = std::type_index(typeid(T));
  int i = 0;
  for (ResourceEntry r : inst.resource_map[type_id])
  {
    log(LogLevel::INFO, std::to_string(i) + ": " + r.path);
    i++;
  }
}

// load files from text files named load.txt, or other 4 keys.txt 
template<typename T>
void loadBatch(const std::string& path)
{
  Text* t = new Text();
  t->load(path);
  std::string subpath = path.substr(0, path.length()-8);
  for (std::string line : t->lines)
  {
    load<T>(subpath + line);
  }

  delete t;
}

// Clear a specific type of resources 
template<typename T>
void clear()
{
  auto type_id = std::type_index(typeid(T));
  inst.resource_map[type_id].clear();
  inst.id_counts[type_id].clear();
}

// Clear all loaded resources 
void clearAll();

}

#endif