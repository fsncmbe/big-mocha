#include <mocha/helper/resource.hpp>

namespace mocha::resource {

const char* Text::load(const std::string& path)
{
  std::ifstream file(path);

  if (!file.is_open()) { return "COULD NOT OPEN FILE"; }

  std::string line;
  while (std::getline(file, line))
  {
    lines.push_back(line);
  }

  return "SUCCESS";
}

void clearAll()
{
  inst.resource_map.clear();
  inst.id_counts.clear();
}


}