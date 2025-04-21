#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <map>
#include <vector>

#include <glad/glad.h>
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>

namespace mocha
{
// 3d rendering namespace
namespace graphics
{   
    struct Vertex 
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;
    };

    struct Texture
    {
        unsigned int id;
        const char* type;
    };

    // Mesh class, solely used in Model class
    class Mesh
    {

    };

    // Model class, maybe differentiate in color and texture model
    class Model
    {
    public:
        // Initialize model with file
        Model(const char* path);

    private:
        std::vector<Mesh> meshes;
        const char* directory;

        // Loads model from file
        void loadModel();
        // Processes nodes 
        void processNode();
        // Processes mesh
        Mesh processMesh();
    };
}
}

#endif