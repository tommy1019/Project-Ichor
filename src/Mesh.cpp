#include "Mesh.h"

Mesh::Mesh(std::string fileName)
{
    std::ifstream file(std::string("res/models/").append(fileName).c_str(), std::ios::in);;

    if (!file)
    {
        printf("Error loading file: %s\n", std::string("res/models/").append(fileName).c_str());
        throw 1;
    }

    std::vector<Vector3f> verticies;
    std::vector<GLuint> indicies;

    std::string curLine;
    while (getline(file, curLine))
    {
        if (curLine.substr(0, 2) == "v ")
        {
            std::istringstream s(curLine.substr(2));
            Vector3f v;

            s >> v.x;
            s >> v.y;
            s >> v.z;

            verticies.push_back(v);
        }
        if (curLine.substr(0, 2) == "f ")
        {
            GLuint a, b, c;
            
            //TODO: load normals and textures
            GLuint tmp;

            sscanf(curLine.substr(2).c_str(), "%i//%i %i//%i %i//%i", &a, &tmp, &b, &tmp, &c, &tmp);

            a--;
            b--;
            c--;

            indicies.push_back(a);
            indicies.push_back(b);
            indicies.push_back(c);
        }
    }

    numIndicies = indicies.size();

    glGenBuffers(1, &vertexPtr);
    glBindBuffer(GL_ARRAY_BUFFER, vertexPtr);
    glBufferData(GL_ARRAY_BUFFER, 3 * verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &indicePtr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicePtr);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndicies * sizeof(GLuint), indicies.data(), GL_STATIC_DRAW);
}
