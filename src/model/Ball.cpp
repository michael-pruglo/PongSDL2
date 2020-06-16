#include "Ball.hpp"

Ball::Ball(Position pos) :
    rect(config::BALL_SIZE, config::BALL_SIZE, pos),
    xVelocity(config::BALL_SPEED),
    yVelocity(config::BALL_SPEED)
{
}

void Ball::move(Position::value_t dx, Position::value_t dy)
{
    rect.move(dx, dy);
}

std::vector<Sprite> Ball::getSprites() const
{
    return {Sprite(rect)};
}
