#ifndef MODULE_HPP
#define MODULE_HPP

class Module
{
 public:
  enum ModuleTypes{
    M_GRAPHICS,
    M_WINDOW,
    M_MAX
  };

 private:
  static Module* instances[M_MAX];
};

#endif