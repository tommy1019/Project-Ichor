#ifndef MESH_H
#define MESH_H

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include <SDL_opengl.h>

#include "Vector3f.h"

class Mesh
{
    public:
        GLuint vertexPtr;
        GLuint indicePtr;

        int numIndicies;

        Mesh(std::string fileName);
};

#endif
