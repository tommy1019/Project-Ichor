#include "Mesh.h"

Mesh::Mesh(std::string fileName)
{
    std::ifstream file(std::string("res/models/").append(fileName).c_str(), std::ios::in);;

    if (!file)
    {
        printf("Error loading file: %s\n", std::string("res/models/").append(fileName).c_str());
        throw 1;
    }

    std::vector<Vector3f> verticeTemp;
    std::vector<Vector3f> normalTemp;

    std::vector<Vector3f> verticies;
    std::vector<Vector3f> normals;
    std::vector<GLuint> indicies;

    std::vector<Vertex> vertexes;
    std::map<Vertex, int> vertexMap;

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

            verticeTemp.push_back(v);
        }
        if (curLine.substr(0, 2) == "vn")
        {
            std::istringstream s(curLine.substr(2));
            Vector3f v;

            s >> v.x;
            s >> v.y;
            s >> v.z;

            normalTemp.push_back(v);
        }
        if (curLine.substr(0, 2) == "f ")
        {
            GLuint pA, pB, pC;
            GLuint nA, nB, nC;
            
            //TODO: load textures

            sscanf(curLine.substr(2).c_str(), "%i//%i %i//%i %i//%i", &pA, &nA, &pB, &nB, &pC, &nC);

            Vertex a(verticeTemp[pA - 1], normalTemp[nA - 1]);
            Vertex b(verticeTemp[pB - 1], normalTemp[nB - 1]);
            Vertex c(verticeTemp[pC - 1], normalTemp[nC - 1]);

            if (vertexMap.find(a) == vertexMap.end())
            {
                vertexMap[a] = vertexes.size();
                indicies.push_back(vertexes.size());
                vertexes.push_back(a);
            }
            else
            {
                indicies.push_back(vertexMap[a]); 
            }

            if (vertexMap.find(b) == vertexMap.end())
            {
                vertexMap[b] = vertexes.size();
                indicies.push_back(vertexes.size());
                vertexes.push_back(b);
            }
            else
            {
                indicies.push_back(vertexMap[b]);
            }

            if (vertexMap.find(c) == vertexMap.end())
            {
                vertexMap[c] = vertexes.size();
                indicies.push_back(vertexes.size());
                vertexes.push_back(c);
            }
            else
            {
                indicies.push_back(vertexMap[c]);
            }

        }
    }

    numIndicies = indicies.size();

    for(int i = 0; i < vertexes.size(); i++)
    {
        Vertex v = vertexes[i];
        verticies.push_back(v.p);
        normals.push_back(v.n);
    }

    glGenBuffers(1, &vertexPtr);
    glBindBuffer(GL_ARRAY_BUFFER, vertexPtr);
    glBufferData(GL_ARRAY_BUFFER, 3 * verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &normalPtr);
    glBindBuffer(GL_ARRAY_BUFFER, normalPtr);
    glBufferData(GL_ARRAY_BUFFER, 3 * normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &indicePtr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicePtr);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndicies * sizeof(GLuint), indicies.data(), GL_STATIC_DRAW);
}
