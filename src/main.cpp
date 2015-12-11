#include <iostream>
#include <string>
#include <chrono>

#include <GL/glew.h>

#include "Window.h"
#include "Vector3f.h"
#include "Program.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Matrix4f.h"

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
        printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
    }

    Shader vertexShader = Shader("basic_vertex.vs", Shader::VERTEX_SHADER);   
    Shader fragmentShader = Shader("basic_fragment.fs", Shader::FRAGMENT_SHADER);   
    
    program = new Program(vertexShader, fragmentShader);

    Mesh mesh = Mesh("monkey.obj");
    Texture texture = Texture("brickTexture.png");
    Texture normalMap = Texture("brickNormal.png");
    Matrix4f transform;
    transform.initTranslation(Vector3f(0,0,-.5));

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glShadeModel(GL_SMOOTH);

    glUseProgram(program->programPtr);
    
    GLuint texLoc = glGetUniformLocation(program->programPtr, "texture");
    glUniform1i(texLoc, 0);
    printf("Texture Loc: %i\n", texLoc);
    
    GLuint normalLoc = glGetUniformLocation(program->programPtr, "normalMap");
    glUniform1i(normalLoc, 1);
    printf("Normal Loc: %i\n", normalLoc);

    bool running = true;
    SDL_Event e;

    long cur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
    long last = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

    int frameCount = 0;
    long elapsed = 0;
    long second = 1000;

    float temp = 0;

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

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.texturePtr);
        glUniform1i(texLoc, 0);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, normalMap.texturePtr);
        glUniform1i(normalLoc, 1);

        temp += 0.02;

        Matrix4f translation;
        translation.initTranslation(Vector3f(cos(temp), 0, -10 + sin(temp)));

        Matrix4f scale;
        scale.initScale(Vector3f(2, 2, 2));

        Matrix4f rotation;
        rotation.initRotation(Vector3f(0, cos(temp / 2), 0));

        transform = translation * rotation * scale;

        glUniformMatrix4fv(glGetUniformLocation(program->programPtr, "transformMatrix"), 1, GL_FALSE, &(transform.a[0][0]));

        Matrix4f projection;
        projection.initProjection(800, 600, 70, 0.1f, 1000);
        projection = projection * transform;

        glUniformMatrix4fv(glGetUniformLocation(program->programPtr, "projectionMatrix"), 1, GL_FALSE, &(projection.a[0][0]));

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexPtr);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.normalPtr);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.texturePtr);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.indicePtr);
        glDrawElements(GL_TRIANGLES, mesh.numIndicies, GL_UNSIGNED_INT, NULL);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glUseProgram(0);

        window.swapWindow();
    } 

    window.destroy();

    return 0;
}
