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

  window->init(screen_size);
  graphics->init();

  // Pre render stuff
  mocha::Cube cube({1.0f, 1.0f, 1.0f});
  glm::vec3 trans({5.0f, 0.0f, -20.0f});
  // Game loop
  while(window->keepGameLoop())
  {
    // Game updates here
    window->getInputs();
    window->clearWindow();

    // Render
    graphics->readyRender();

    graphics->draw(&cube, trans);

    window->swapBuffers();
  }

  window->closeWindow();
  exit(0);
}
