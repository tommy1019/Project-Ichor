#version 120

attribute vec3 vertexIn;
attribute vec3 normalIn;
attribute vec2 textureIn;

varying vec3 pos;
varying vec3 normal;
varying vec2 texCoord;

void main(void)
{
    pos = vertexIn * vec3(0.5, 0.5, 0.5) + vec3(0.0, 0.0, -0.5);
    normal = normalIn;
    texCoord = textureIn;    

    gl_Position = vec4(pos, 1.0);
}
