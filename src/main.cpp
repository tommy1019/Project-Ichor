#include <iostream>
#include <string>
#include <chrono>

#include <SDL.h>
#include <SDL_opengl.h>

#include "Window.h"
#include "Vector3f.h"
#include "Program.h"
#include "Shader.h"
#include "Mesh.h"

using namespace std;

Program* program;

int main(int argc, char ** argv)
{
    cout << "Project Ichor v0.0.0 Starting up...\n";

    Window window = Window(800, 600);

    Shader vertexShader = Shader("basic_vertex.vs", Shader::VERTEX_SHADER);   
    Shader fragmentShader = Shader("basic_fragment.fs", Shader::FRAGMENT_SHADER);   
    
    program = new Program(vertexShader, fragmentShader);

    Mesh mesh = Mesh("monkey.obj");

    bool running = true;
    SDL_Event e;

    long cur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
    long last = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

    int frameCount = 0;
    long elapsed = 0;
    long second = 1000;

    while (running)
    {
        SDL_PollEvent(&e);

        cur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
        int delta = cur - last;
        last = cur;

        frameCount++;
        elapsed += delta;
        if (elapsed > second)
        {
            cout << frameCount << " fps\n";
            elapsed = 0;
            frameCount = 0;
        }

        if (e.type == SDL_QUIT)
        {
            running = false;
        }
    
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program->programPtr);

        glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexPtr);
        glEnableVertexAttribArray(program->vertexAttrib);
        glVertexAttribPointer(program->vertexAttrib, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.indicePtr);

        glDrawElements(GL_TRIANGLES, mesh.numIndicies, GL_UNSIGNED_INT, NULL);

        glDisableVertexAttribArray(0);
        glUseProgram(NULL);

        window.swapWindow();
    } 

    window.destroy();

    return 0;
}
