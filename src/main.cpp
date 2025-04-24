#include <iostream>

#include "modules/window/window.hpp"
#include "modules/graphics/graphics.hpp"

int main(int argc, const char *argv[])
{
    // Init modules
    mocha::window::init(300, 300);
    mocha::graphics::init();

    // Game loop
    while(mocha::window::keepGameLoop())
    {
        // Game updates here

        // Clears window of all rendered things of last frame
        mocha::window::clearWindow();

        // Render stuff here
        

        // Pushes all rendered stuff from buffers to the screen
        mocha::window::swapBuffers();
    }

    return 0;
}
