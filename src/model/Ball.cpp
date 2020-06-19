#include "Ball.hpp"
#include "../utility/Random.hpp"
#include "../view/RectSprite.hpp"

Ball::Ball(Position pos) :
    rect(config::BALL_SIZE, config::BALL_SIZE, pos),
    velocity({ballInitAngle(), config::BALL_SPEED_INIT})
{
}

void Ball::reflectX()
{
    velocity.angle = M_PI-velocity.angle; if (velocity.angle<0) velocity.angle+=2*M_PI; increaseSpeed();
}

void Ball::reflectY()
{
    velocity.angle = -velocity.angle; if (velocity.angle<0) velocity.angle+=2*M_PI;
}

void Ball::increaseSpeed()
{
    velocity.len=std::min(velocity.len+config::BALL_ACCELERATION_DELTA, config::BALL_SPEED_MAX);
}

double Ball::ballInitAngle()
{
    auto a = Random::getAngleInRadians(0, config::MAX_BALL_ANGLE);
    switch (Random::getInt(0,3))
    {
        case 0: return a;
        case 1: return M_PI-a;
        case 2: return M_PI+a;
        case 3: return 2*M_PI-a;
        default: return 0.0;
    }
}

std::vector<std::unique_ptr<ISprite>> Ball::getSprites() const
{
    std::vector<std::unique_ptr<ISprite>> res;
    res.push_back(std::unique_ptr<ISprite> {
        new RectSprite(rect,
                      {config::BALL_COLOR.r,config::BALL_COLOR.g,config::BALL_COLOR.b,config::BALL_COLOR.a})
    });
    return res;
}
