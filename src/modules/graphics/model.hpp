#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

#include "mesh.hpp"

namespace mocha{
namespace graphics
{
    // Model class, maybe differentiate in color and texture model
    class Model
    {
    public:
        // Initialize model with file
        Model(const char* path);

    private:
        std::vector<Mesh> meshes;
        const char* directory;
    };
}
}


#endif