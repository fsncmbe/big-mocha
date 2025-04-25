#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "modules/window/window.hpp"
#include "modules/graphics/graphics.hpp"

int main(int argc, const char *argv[])
{
    // Init modules
    Window::instance()->init(500, 500);
    Graphics::instance()->init();

    Rectangle rect({20, 20});
    glm::mat4 trans(1.0f);

    // Game loop
    while(Window::instance()->keepGameLoop())
    {
        // Game updates here

        // Clears window of all rendered things of last frame
        Window::instance()->clearWindow();
        // Render stuff here
        Graphics::instance()->useShader();
        
        Graphics::instance()->draw(&rect, trans);

        Window::instance()->swapBuffers();
    }

    Window::instance()->closeWindow();

    return 0;
}
