#ifndef PONG_RECTSPRITE_HPP
#define PONG_RECTSPRITE_HPP

#include "../controller/ISprite.hpp"
#include "../utility/Rectangle.hpp"

class RectSprite : public ISprite
{
public:
    explicit RectSprite(const Rectangle& rectangle);
    void render(SDL_Renderer *renderer) const override;
private:
    SDL_Rect rect;
};


#endif //PONG_RECTSPRITE_HPP
