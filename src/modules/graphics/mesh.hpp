#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "gtypes.hpp"

namespace mocha {
namespace graphics
{
    class Mesh
    {
    public:
        std::vector<Vertex>         vertices;
        std::vector<unsigned int>   indices;
        std::vector<Texture>        textures;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    private:
        unsigned int VAO, VBO, EBO;

        void setupMesh();
    };
}
}



#endif