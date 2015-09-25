#include "Window.h"

Window::Window(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    
    win = SDL_CreateWindow("Project Ichor", 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(win);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Window::swapWindow()
{
    SDL_GL_SwapWindow(win);
}

void Window::destroy()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);

    SDL_Quit();
}
