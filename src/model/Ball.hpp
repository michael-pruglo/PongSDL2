#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include "../view/IRenderable.hpp"
#include "../utility/Position.hpp"
#include "../Config.hpp"
#include "../utility/Rectangle.hpp"
#include "../utility/Random.hpp"

class Ball : public IRenderable
{
public:
    explicit            Ball(Position pos = Position(config::SCREEN_CENTER_X-config::BALL_SIZE/2., config::SCREEN_CENTER_Y-config::BALL_SIZE/2.)) :
                            rect(config::BALL_SIZE, config::BALL_SIZE, pos),
                            velAngle(Random::getAngleInRadians()) //TODO: choose nice angles
                            {}

    inline Rectangle    getRect() const { return rect; }
    inline void         moveTo(Position position) { rect.moveTo(position); }
    inline void         update() { moveTo(nextPosition()); }
    inline void         reflectX() { velAngle = M_PI-velAngle; if (velAngle<0) velAngle+=2*M_PI; }
    inline void         reflectY() { velAngle = -velAngle; if (velAngle<0) velAngle+=2*M_PI; }
    inline Position     currPosition() const { return rect.position(); }
    inline Position     nextPosition() const { return Position(currPosition().getX() + std::cos(velAngle) * config::BALL_SPEED,
                                                               currPosition().getY() + std::sin(velAngle) * config::BALL_SPEED); }
private:
    Rectangle rect;
    double velAngle;


public:
    std::vector<Sprite> getSprites() const override { return {Sprite(rect)}; }
};


#endif //PONG_BALL_HPP
