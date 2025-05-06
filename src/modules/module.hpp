#ifndef MODULE_HPP
#define MODULE_HPP

namespace mocha {

template <typename T>
class Module
{
 public:
  static T* inst()
  {
    static T instance;
    return &instance;
  }
  
  protected:
  Module() {};
  ~Module() {};
};

}

#endif