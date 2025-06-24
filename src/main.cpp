#include <iostream>

#include <mocha/helper/log.hpp>
#include <mocha/helper/resource.hpp>
#include <mocha/graphics/render.hpp>
#include <mocha/window/window.hpp>
#include <mocha/ecs/entity.hpp>

using namespace mocha;

int main()
{
  // Init
  window::init();

  // Log settings
  addLogLevel(LogLevel::DEBUG);
  log(LogLevel::DEBUG, "Init done");

  // Load files of each type
  resource::loadBatch<graphics::Shader>("../assets/shaders/load.txt");
  resource::loadBatch<resource::Text>("../assets/texts/load.txt");
  resource::loadBatch<graphics::Texture>("../assets/textures/load.txt");
  resource::loadBatch<graphics::Model>("../assets/models/load.txt");

  // Set shader and camera
  graphics::setShader(resource::get<graphics::Shader>(0));
  graphics::setCamera(new graphics::Camera());

  // Load Model
  graphics::Model* m = resource::get<graphics::Model>(0);

  int e = ecs::createEntity();
  ecs::addComponent<ecs::Position>(e, 0.0f, 0.0f, 0.0f);

  // Bind window dt to this scope dt for ease of use
  float* dt = window::getDT();

  // Main game loop
  while (window::gameLoop())
  {
    // Game Logic
    

    // Update Graphics and start draw calls
    mocha::graphics::update(*dt);
    graphics::draw(*m, {2, 0, -20}, {1, 1, 1});
  }


  resource::clearAll();
  log(LogLevel::DEBUG, "Engine Shutdown");
  return 0;
}