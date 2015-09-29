#ifndef PROGRAM_H
#define PROGRAM_H

#include <gl/glew.h>

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
