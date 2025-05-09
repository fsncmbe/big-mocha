#version 330 core
layout (location = 0) in vec3 position_;
layout (location = 1) in vec3 normal_;
layout (location = 2) in vec2 tex_coord_;

out vec3 frag_pos;
out vec3 normal;
out vec2 tex_coord;

uniform mat4 trans;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    frag_pos = vec3(trans * vec4(position_, 1.0));
    normal = mat3(transpose(inverse(trans))) * normal_;

    tex_coord = vec2(tex_coord_.x, tex_coord_.y);
    gl_Position = projection * view * vec4(frag_pos, 1.0f);
}