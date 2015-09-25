#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>

#include "Window.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Project Ichor v0.0.0 Starting up...\n";

    Window window = Window(800, 600);

    bool running = true;
    SDL_Event e;
    
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
}
