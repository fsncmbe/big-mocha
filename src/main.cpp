#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/window/window.hpp"
#include "modules/graphics/graphics.hpp"
#include "modules/log/log.hpp"

int main(int argc, const char *argv[])
{
  // Bind instances 
  mocha::Log* log = mocha::Module<mocha::Log>::inst();
  mocha::Window* window = mocha::Module<mocha::Window>::inst();
  mocha::Graphics* graphics = mocha::Module<mocha::Graphics>::inst();

  mocha::EventCatcher event_catcher;

  // Settings
  glm::vec2 screen_size(500, 500);

  window->getSubject()->addObserver(log)->addObserver(graphics)->addObserver(&event_catcher);
  graphics->getSubject()->addObserver(log)->addObserver(&event_catcher);
  mocha::Module<mocha::Resource>::inst()->getSubject()->addObserver(log)->addObserver(&event_catcher);

  // Init
  window->init(screen_size);
  graphics->init();

  // Pre render stuff
  std::pair<mocha::Cube, glm::vec3> cubes[]= {
    {mocha::Cube({1.0f, 1.0f, 1.0f}), {0, 0, -8}},
    {mocha::Cube({1.0f, 1.0f, 1.0f}), {-2, 0, 0}},
  };

  // Game loop
  while(window->keepGameLoop())
  {

    // Render
    window->clearWindow();
    graphics->readyRender();

    for (auto p : cubes)
    {
      graphics->draw(&p.first, p.second);
    }

    window->swapBuffers();
  }

  window->closeWindow();
  exit(0);
}
