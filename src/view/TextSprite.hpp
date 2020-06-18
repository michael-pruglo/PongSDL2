#ifndef PONG_TEXTSPRITE_HPP
#define PONG_TEXTSPRITE_HPP

#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "../utility/Position.hpp"
#include "../controller/ISprite.hpp"

class TextSprite : public ISprite
{
public:
    TextSprite(std::string text, int size, Position position = Position());
    void render(SDL_Renderer* renderer) const override;
private:
    std::string txt;
    Position pos;
    TTF_Font* font;
};


#endif //PONG_TEXTSPRITE_HPP
