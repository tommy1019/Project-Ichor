#include <iostream>
#include <string>
#include <chrono>

#include <gl/glew.h>

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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	
    Window window = Window(800, 600);

    glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
    }

    Shader vertexShader = Shader("basic_vertex.vs", Shader::VERTEX_SHADER);   
    Shader fragmentShader = Shader("basic_fragment.fs", Shader::FRAGMENT_SHADER);   
    
    program = new Program(vertexShader, fragmentShader);

    Mesh mesh = Mesh("monkeySmooth.obj");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);

    glShadeModel(GL_SMOOTH);

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
    
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program->programPtr);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexPtr);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.normalPtr);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.indicePtr);
        glDrawElements(GL_TRIANGLES, mesh.numIndicies, GL_UNSIGNED_INT, NULL);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glUseProgram(NULL);

        window.swapWindow();
    } 

    window.destroy();

    return 0;
}
