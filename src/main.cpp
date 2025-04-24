#include <iostream>

#include "modules/window/window.hpp"
#include "modules/graphics/graphics.hpp"

int main(int argc, const char *argv[])
{
    // Init modules
    mocha::window::init(500, 500);
    mocha::graphics::init();

    //TESTING

    mocha::graphics::Rectangle rect(glm::vec2(100, 100));
    glm::mat4 trans = glm::mat4(1.0f);

    // Game loop
    while(mocha::window::keepGameLoop())
    {
        // Game updates here

        // Clears window of all rendered things of last frame
        mocha::window::clearWindow();

        // Render stuff here
        mocha::graphics::draw(&rect, trans);

        // Pushes all rendered stuff from buffers to the screen
        mocha::window::swapBuffers();
    }

    return 0;
}
