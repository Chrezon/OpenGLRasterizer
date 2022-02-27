#version 330 core

in vec2 position;
in float colour;

out float Colour;

void main()
{
    Colour = colour;
    gl_Position = vec4(position, 0.0, 1.0);
}