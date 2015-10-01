#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <SDL_image.h>
#include <gl/glew.h>

class Texture
{
    public:
        GLuint texturePtr;

        Texture(std::string fileName);
};

#endif
