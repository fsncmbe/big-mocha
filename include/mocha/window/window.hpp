#ifndef MOCHAWINDOW_HPP
#define MOCHAWINDOW_HPP

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <mocha/helper/log.hpp>

namespace mocha::window {

void init();
bool gameLoop();
float* getDT();

}

#endif