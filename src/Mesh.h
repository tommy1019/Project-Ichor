#ifndef MESH_H
#define MESH_H

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

#include <gl/glew.h>

#include "Vector3f.h"
#include "Vector2f.h"

class Mesh
{
    public:
        GLuint vertexPtr;
        GLuint normalPtr;
        GLuint texturePtr;
        GLuint indicePtr;

        int numIndicies;

        Mesh(std::string fileName);
    private:
        struct Vertex
        {
            Vector3f p;
            Vector3f n;
            Vector2f t;

            Vertex(Vector3f p, Vector3f n, Vector2f t)
            {
                this->p = p;
                this->n = n;
                this->t = t;
            };

            bool operator<(const Vertex& a) const
            {
                if (p.x != a.p.x) return p.x < a.p.x;
                if (p.y != a.p.y) return p.y < a.p.y;
                if (p.z != a.p.z) return p.z < a.p.z;
            
                if (n.x != a.n.x) return n.x < a.n.x;
                if (n.y != a.n.y) return n.y < a.n.y;
                if (n.z != a.n.z) return n.z < a.n.z;
            
                if (t.x != a.t.x) return t.x < a.t.x;
                if (t.y != a.t.y) return t.y < a.t.y;

                return true;
            };
        };
};

#endif
