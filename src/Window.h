#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <SDL2/SDL_image.h>

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
