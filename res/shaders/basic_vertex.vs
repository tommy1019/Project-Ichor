#version 120

attribute vec3 vertexIn;
attribute vec3 normalIn;
attribute vec2 textureIn;

uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;

varying vec3 posOut;
varying vec3 normalOut;
varying vec2 texCoordOut;

void main(void)
{
    gl_Position = projectionMatrix * vec4(vertexIn, 1);

    normalOut = (transformMatrix * vec4(normalIn, 0)).xyz;
    texCoordOut = textureIn;    
    posOut = (transformMatrix * vec4(vertexIn, 1)).xyz;
}
