#include <iostream>

#include "window/window.hpp"

int main(int argc, const char *argv[])
{
    // Init window
    mocha::window::initWindow(1080, 1920);

    // Render loop
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
