#include "Texture.h"

Texture::Texture(std::string texture)
{
    SDL_Surface* surface = IMG_Load(std::string("res/textures/").append(texture).c_str());
    if (surface == NULL)
    {
        printf("Error loading texture");
        throw 1;
    }

    glGenTextures(1, &texturePtr);
    glBindTexture(GL_TEXTURE_2D, texturePtr);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(surface);
}
