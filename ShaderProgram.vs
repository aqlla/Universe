#version 410 core

in vec2 position;

void main() {
    /* gl_Position is of type vec4, so create new vec4 with position
     * populating the x, y values, and set z to 0 and w to 1. */
    gl_Position = vec4(position, 0, 1);
}