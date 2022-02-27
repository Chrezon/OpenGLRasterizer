#version 330 core

in float Colour;
out vec4 outColour;

void main()
{
    outColour = vec4(Colour, Colour, Colour, 1.0f);
}