#version 120

attribute vec3 vertex;
attribute vec3 normal;
attribute vec2 texCoord;

uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;

varying vec3 vPos;
varying vec3 vNormal;
varying vec2 vTexCoord;

void main(void)
{
    gl_Position = projectionMatrix * vec4(vertex, 1);

    vNormal = (transformMatrix * vec4(normal, 0)).xyz;
    vTexCoord = vec2(texCoord.x, -texCoord.y); 
    vPos = (transformMatrix * vec4(vertex, 1)).xyz;
}
