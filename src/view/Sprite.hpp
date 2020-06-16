#ifndef PONG_SPRITE_HPP
#define PONG_SPRITE_HPP

#include <string>
#include <SDL2/SDL.h>
#include "../utility/Rectangle.hpp"

class Sprite
{
public:
    explicit Sprite(const Rectangle& rectangle);
    explicit Sprite(const std::string& rectangle);

    void render(SDL_Renderer* renderer) const;
private:
    SDL_Rect rect;
};


#endif //PONG_SPRITE_HPP
