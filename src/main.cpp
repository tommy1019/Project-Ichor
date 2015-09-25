#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

int main(int argc, char ** argv)
{
  cout << "Project Ichor v0.0.0 Starting up...\n";
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return 1;
  }

  SDL_Window* displayWindow;
  SDL_Renderer* displayRenderer;
  SDL_RendererInfo displayRendererInfo; 
 
  SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
  SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);

  if ((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 || (displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0)
  {
    std::cout << "Error no opengl\n";
    return 1;
  }

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

    SDL_RenderPresent(displayRenderer);
  } 
  SDL_Quit();
}
