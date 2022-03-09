#version 330 core

in vec2 position;
in vec3 colour;

uniform mat4 transform;

out vec3 Colour;

void main()
{
    Colour = colour;
    gl_Position = transform * vec4(position, 0.0, 1.0);
}