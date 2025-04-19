#ifndef RENDER_HPP
#define RENDER_HPP

#include <map>

#include <glad/glad.h>
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "resource.c++"

// 3d rendering namespace
namespace MochaRender
{
    struct Shader : ResourceManager::File
    {
        void load(const char* path)
        {
            // Load shader 
        }

    };

    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texcoord;
    };

    struct Texture
    {
        unsigned int id;
        const char* type;
        const char* path;
    };

    struct Mesh
    {
        std::vector<Vertex>         vertices;
        std::vector<unsigned int>   indices;
        std::vector<Texture>        textures;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
        {
            this->vertices = vertices;
            this->indices = indices;
            this->textures = textures;

            // setup Mesh here
        }

        void draw()
        {

        }
    };

    struct Model
    {
        std::vector<Mesh>   meshes;
        

        Model(char* path)
        {

        }

        
    };

    struct Render
    {
        
    };
}

#endif