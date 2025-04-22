#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

#include "mesh.hpp"
#include "drawable.hpp"

namespace mocha{
namespace graphics
{
    // Model class, maybe differentiate in color and texture model
    class Model : public Drawable
    {
    public:
        // Initialize model with file
        Model(const char* path);

        // Drawable
        void draw();
        
    private:
        std::vector<Mesh> meshes;
        const char* directory;
    };
}
}


#endif