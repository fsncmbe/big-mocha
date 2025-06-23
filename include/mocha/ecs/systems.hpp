#ifndef MOCHASYSTEMS_HPP
#define MOCHASYSTEMS_HPP

#include <map>

#include <mocha/ecs/entity.hpp>
#include <mocha/window/window.hpp>
#include <mocha/graphics/render.hpp>
#include <mocha/graphics/camera.hpp>
#include <mocha/helper/resource.hpp>

// This encapsulates all components and systems in one 
// file to use in main when creating entities

namespace mocha::ecs {

// Components

struct PositionComponent : public IComponent
{
  glm::vec3 position;
};

struct InputComponent : public IComponent
{
  std::map<const char*, int> inputs;
};

struct RenderComponent : public IComponent
{
  
};

// Systems

class WindowSystem : public ISystem
{
 public:
  void update(float dt);
};

class RenderSystem : public ISystem
{
 public:
  void update(float dt);
};

class InputSystem : public ISystem
{
 public:
  void update(float dt);
};

class CameraSystem : public ISystem
{
 public:
  void update(float dt);
};

}

#endif