#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <fstream>
#include <string>

#include <GL/glew.h>

class Shader
{
    public:
        static const GLuint VERTEX_SHADER = GL_VERTEX_SHADER;
        static const GLuint FRAGMENT_SHADER = GL_FRAGMENT_SHADER;

        GLuint shaderPtr;

        Shader(std::string fileName, GLuint shaderType);
    private:
        void printShaderLog(GLuint shaderPtr);
};

#endif
