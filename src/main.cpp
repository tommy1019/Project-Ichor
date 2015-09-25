#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>

#include "Window.h"
#include "Vector3f.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Project Ichor v0.0.0 Starting up...\n";

    Window window = Window(800, 600);

    bool running = true;
    SDL_Event e;

    Vector3f a = Vector3f(1,2,3);
    Vector3f b = Vector3f(4,5,6);
    Vector3f c = a + b;

    cout << "(" << c.x << "," << c.y << "," << c.z << ")\n";
    
    while (running)
    {
        SDL_PollEvent(&e);
      
         if (e.type == SDL_QUIT)
         {
             running = false;
         }
    
         glLoadIdentity();
         glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
         glClear(GL_COLOR_BUFFER_BIT);

         glColor3f(0.0f, 0.0f, 1.0f);
    
         glBegin(GL_TRIANGLES);
         glVertex3f(-1,0,0);
         glVertex3f(1,0,0);
         glVertex3f(0,1,0);
         glEnd();

         window.swapWindow();
    } 

    window.destroy();

    return 0;
}
