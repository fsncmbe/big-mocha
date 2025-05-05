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

  // Init modules 
  log->init();
  window->getSubject()->addObserver(log);
  window->init(500, 500);
  graphics->getSubject()->addObserver(log);
  graphics->init();

  // Pre render stuff
  mocha::Rectangle rect({0.5, 0.5});
  glm::mat4 trans(1.0f);

  // Game loop
  while(window->keepGameLoop())
  {
    // Game updates here
    window->getInputs();

    // Clears window of all rendered things of last frame
    window->clearWindow();

    // Render stuff here
    graphics->useShader();
    
    graphics->draw(&rect, trans);

    // Swaps buffer, ender of render
    window->swapBuffers();
  }

  window->closeWindow();

  return 0;
}
