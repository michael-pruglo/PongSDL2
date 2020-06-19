#include "RectSprite.hpp"

RectSprite::RectSprite(const Rectangle& rectangle, SDL_Color color) :
    col(color)
{
    rect.x = rectangle.position().getX();
    rect.y = rectangle.position().getY();
    rect.w = rectangle.width();
    rect.h = rectangle.height();
}

void RectSprite::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
    SDL_RenderFillRect(renderer, &rect);
}
