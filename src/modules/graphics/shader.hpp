#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "glad/glad.h"

namespace mocha
{
namespace graphics
{
    class Shader
    {
    public:
        unsigned int id;
        
        // Initialize shader with file
        Shader(const char* vertex_path, const char* fragment_path);
        
        // Set current shader to this one
        void use();

        // Set uniform variables 
        void setBool(const char* name, bool value);
        void setInt(const char* name, int value);
        void setFload(const char* name, float value);
    private:
        
    };
};
};



#endif