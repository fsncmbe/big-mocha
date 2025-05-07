#ifndef INPUT_HPP
#define INPUT_HPP

#include <map>
#include <string>

#include "../module.hpp"
#include "window.hpp"
#include "../log/log.hpp"

namespace mocha {

class Input
{
 friend class Module<Input>;
 public:
  enum class KeyState
  {
    kUp = 0,
    kPressed,
    kDown,   
    kReleased,
    kUnknown
  };

  static std::string keyStateToString(KeyState state);

  KeyState getKey(int key);
  glm::vec2 getMousePos();

 private:
  std::map<int, KeyState> key_state_map_;
};

}

#endif