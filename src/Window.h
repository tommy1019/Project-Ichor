#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>

class Window
{
    private:
        SDL_Window* win;
        SDL_GLContext context;
    public:
        Window(int width, int height);

        void swapWindow();
        void destroy();
};

#endif
