#ifndef GRAPHIC_C_HPP
#define GRAPHIC_C_HPP

#include "component.hpp"
#include "../graphics/graphics.hpp"

#include "glm/glm.hpp"

// Graphic component for an entity
class Graphic_c : public Component
{
public:
    void update();

    // Render call for all drawable things
    void render(glm::mat4 trans);

    // Defines Drawable for component
    void defDrawable(Drawable* draw);
private:

    Drawable* drawable;
};

#endif