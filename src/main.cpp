#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Project Ichor v0.0.0 Starting up...\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* win;
    win = SDL_CreateWindow("SDL Application", 100, 100, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GLContext context;
    context = SDL_GL_CreateContext(win);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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

         SDL_GL_SwapWindow(win);
    } 
    SDL_Quit();
}
