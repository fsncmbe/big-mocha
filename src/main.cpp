#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/window/window.hpp"
#include "modules/graphics/graphics.hpp"
#include "modules/log/log.hpp"

int main(int argc, const char *argv[])
{
    // First add observers, then init
    Log::instance()->init();

    Window::instance()->getSubject()->addObserver(Log::instance());
    Window::instance()->init(500, 500);

    Graphics::instance()->getSubject()->addObserver(Log::instance());
    Graphics::instance()->init();

    Rectangle rect({0.5, 0.5});
    glm::mat4 trans(1.0f);

    // Game loop
    while(Window::instance()->keepGameLoop())
    {
        // Game updates here
        Window::instance()->getInputs();

        // Clears window of all rendered things of last frame
        Window::instance()->clearWindow();

        // Render stuff here
        Graphics::instance()->useShader();
        
        Graphics::instance()->draw(&rect, trans);

        // Swaps buffer, ender of render
        Window::instance()->swapBuffers();
    }

    Window::instance()->closeWindow();

    return 0;
}
