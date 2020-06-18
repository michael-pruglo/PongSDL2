#ifndef PONG_ISPRITE_HPP
#define PONG_ISPRITE_HPP

#include "SDL_render.h"

class ISprite
{
public:
    virtual void render(SDL_Renderer* renderer) const = 0;
};


#endif //PONG_ISPRITE_HPP
