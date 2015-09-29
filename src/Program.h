#ifndef PROGRAM_H
#define PROGRAM_H

#include <SDL_opengl.h>

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
