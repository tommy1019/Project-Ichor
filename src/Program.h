#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/glew.h>

#include "Shader.h"

class Program
{
    public:
        GLuint programPtr;

        Program(Shader vs, Shader fs);
    private:
        void printProgramLog();
};

#endif
