#include "RectSprite.hpp"

RectSprite::RectSprite(const Rectangle& rectangle)
{
    rect.x = rectangle.position().getX();
    rect.y = rectangle.position().getY();
    rect.w = rectangle.width();
    rect.h = rectangle.height();
}

void RectSprite::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
