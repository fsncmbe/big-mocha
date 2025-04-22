#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

namespace mocha{
namespace graphics
{
    // Used as Supertype for all drawable objects
    class Drawable
    {
        virtual void draw() = 0;
    };
}
}

#endif