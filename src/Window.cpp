#include "Window.h"

Window::Window(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        throw(1);
    }
    
	int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init( imgFlags ) & imgFlags ))
    {
        printf( "IMG_Init Error: %s\n", IMG_GetError() );
        throw(1);
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
