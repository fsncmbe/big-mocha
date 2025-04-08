#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "include/glad/glad.h"

int main(int argc, const char *argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int kwidth = 800;
    int kheight = 800;

    if (argc > 1)
    {
        kwidth = atoi(argv[1]);
        kheight = atoi(argv[2]);
    }

    //Create Window
    GLFWwindow* window = glfwCreateWindow(kwidth, kheight, "GameEngine", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create glfw window" << "\n";
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << "\n";
        return -1;
    }

    // Render loop
    while(!glfwWindowShouldClose(window))
    {

        // Fill screen with color
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Update screen
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Terminate window
    glfwTerminate();
    return 0;
}
