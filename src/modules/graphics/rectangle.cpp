#include "rectangle.hpp"
     
mocha::graphics::Rectangle::Rectangle(glm::vec2 size)
{
    glm::vec2 size_n = glm::normalize(size);
    scaler = {size.x/size_n.x, size.y/size_n.y, 1};
    size_n -= size_n * 0.5f;
    std::cout << size_n.y;
    float vertices[] = {
        -size_n.x, -size_n.y, 0.0f,
         size_n.x, -size_n.y, 0.0f,
         size_n.x,  size_n.y, 0.0f,
        -size_n.x,  size_n.y, 0.0f
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void mocha::graphics::Rectangle::draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

