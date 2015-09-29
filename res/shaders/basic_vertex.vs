#version 120

attribute vec3 vertexIn;
attribute vec3 normalIn;

varying vec3 pos;
varying vec3 normal;

void main(void)
{
    pos = vertexIn * vec3(0.5, 0.5, 0.5) + vec3(0.0, 0.0, -0.5);
    normal = normalize(normalIn);
    gl_Position = vec4(pos, 1.0);
}
