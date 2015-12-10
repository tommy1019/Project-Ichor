#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <GL/glew.h>
#include <SDL2/SDL_image.h>

class Texture
{
    public:
        GLuint texturePtr;

        Texture(std::string fileName);
};

#endif
