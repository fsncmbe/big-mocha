#version 330 core
layout (location = 0) in vec3 position_;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;

void main()
{
  gl_Position = projection * view * model * vec4(position_, 1.0f);
  ourColor = vec3(1.0f, 1.0f, 1.0f);
}