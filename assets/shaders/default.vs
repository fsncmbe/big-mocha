#version 330 core
layout (location = 0) in vec3 position_;
layout (location = 1) in vec2 uv_;

uniform mat4 trans;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * vec4(frag_pos, 1.0f);
}