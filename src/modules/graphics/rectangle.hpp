#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "drawable.hpp"

namespace mocha {
namespace graphics
{
    class Rectangle : public Drawable
    {
    public:
        float vertices[12];
        int indices[6];
        
        Rectangle();

        void draw(glm::mat4 trans);
    private:
    };
}
}


#endif