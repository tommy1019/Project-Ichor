#version 120

attribute vec3 vertexIn;
attribute vec3 normalIn;
attribute vec2 textureIn;

uniform mat4 transformMatrix;

varying vec3 pos;
varying vec3 normal;
varying vec2 texCoord;

void main(void)
{
    vec4 posTemp = vec4(vertexIn, 1) * transformMatrix;

    normal = normalIn;
    texCoord = textureIn;    
    pos = posTemp.xyz;

    gl_Position = posTemp;
}
