#ifndef PONG_RECTSPRITE_HPP
#define PONG_RECTSPRITE_HPP

#include "../controller/ISprite.hpp"
#include "../utility/Rectangle.hpp"

class RectSprite : public ISprite
{
public:
    explicit RectSprite(const Rectangle& rectangle, SDL_Color color={255,255,255,255});
    void     render(SDL_Renderer *renderer) const override;
private:
    SDL_Rect rect;
    SDL_Color col;
};


#endif //PONG_RECTSPRITE_HPP
