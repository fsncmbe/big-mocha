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
        void setBool();
        void setInt();
        void setFload();
    private:
        // Check for compilation error, maybe take out in another class
        void checkCompileErrors();
    };
};
};



#endif