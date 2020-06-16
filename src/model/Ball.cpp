#include "Ball.hpp"

void Ball::move(Position::value_t dx, Position::value_t dy)
{
    rect.move(dx, dy);
}

std::vector<Sprite> Ball::getSprites() const
{
    return {Sprite(rect)};
}
