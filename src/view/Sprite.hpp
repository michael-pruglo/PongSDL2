#ifndef PONG_SPRITE_HPP
#define PONG_SPRITE_HPP

#include <string>
#include "../utility/Rectangle.hpp"

class Sprite
{
public:
    explicit Sprite(const Rectangle& rectangle);
    explicit Sprite(const std::string& rectangle);

};


#endif //PONG_SPRITE_HPP
