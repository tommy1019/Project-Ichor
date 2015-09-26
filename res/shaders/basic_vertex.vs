#version 120

attribute vec3 vertex;

void main(void)
{
    gl_Position = vec4(vertex, 1.0) * vec4(0.5, 0.5, 0.5, 1.0) + vec4(0.0, 0.0, -0.5, 0.0);
}
