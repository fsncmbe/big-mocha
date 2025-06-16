#include <iostream>

#include <mocha/helper/log.hpp>
#include <mocha/helper/resource.hpp>
#include <mocha/graphics/render.hpp>
#include <mocha/window/window.hpp>

using namespace mocha;

int main()
{
  window::init();

  addLogLevel(LogLevel::DEBUG);
  log(LogLevel::DEBUG, "Init done");

  // Load files of each type
  resource::loadBatch<graphics::Shader>("../assets/shaders/load.txt");
  resource::loadBatch<resource::Text>("../assets/texts/load.txt");
  resource::loadBatch<graphics::Texture>("../assets/textures/load.txt");

  // Check which files got loaded
  resource::logFilesLoaded<graphics::Texture>();

  // Prepare for cube render 
  graphics::genCubeData();
  graphics::Texture& cube = *resource::get<graphics::Texture>(0);

  // Set default shader
  graphics::setShader(resource::get<graphics::Shader>(0));

  // Bind window dt to this scope dt for ease of use
  float* dt = window::getDT();

  while (window::gameLoop())
  {
    graphics::draw(cube ,{200, 200}, {130, 150}, 0.0f, {1.0f, 1.0f, 1.0f});
  }

  resource::clearAll();
  log(LogLevel::DEBUG, "Engine Shutdown");
  return 0;
}