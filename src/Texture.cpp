#include "Texture.h"

Texture::Texture(std::string texture)
{
    SDL_Surface* surface = IMG_Load(std::string("res/textures/").append(texture).c_str());
    if (surface == NULL)
    {
        printf("Error loading texture");
        throw 1;
    }

    GLuint textureFormat = GL_RGBA;

    int nColors = surface->format->BytesPerPixel;

    if (nColors == 4)
    {
        if (surface->format->Rmask == 0x000000ff)
            textureFormat = GL_RGBA;
        else
            textureFormat = GL_BGRA;
    }
    else if (nColors == 3)
    {
        if (surface->format->Rmask == 0x000000ff)
            textureFormat = GL_RGB;
        else
            textureFormat = GL_BGR;
    }
    else
    {
        printf("Error loading texture: number of colors is not 3 or 4\n");
        throw 1;
    }

    glGenTextures(1, &texturePtr);
    glBindTexture(GL_TEXTURE_2D, texturePtr);

    glTexImage2D(GL_TEXTURE_2D, 0, nColors, surface->w, surface->h, 0, textureFormat, GL_UNSIGNED_BYTE, surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

    SDL_FreeSurface(surface);
}
