#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include "../controller/IRenderable.hpp"
#include "../Config.hpp"
#include "../utility/Position.hpp"
#include "../utility/Rectangle.hpp"
#include "../utility/MovementVector.hpp"

class Ball : public IRenderable
{
public:
    explicit                Ball(Position pos = Position(config::SCREEN_CENTER_X-config::BALL_SIZE/2.,
                                                         config::SCREEN_CENTER_Y-config::BALL_SIZE/2.));

    inline Rectangle        getRect() const { return rect; }
    inline MovementVector   getVelocityVector() const { return velocity; }
    inline void             moveTo(Position position) { rect.moveTo(position); }
    inline void             update() { moveTo(nextPosition()); }
    void                    reflectX();
    void                    reflectY();
    inline Position         currPosition() const { return rect.position(); }
    inline Position         nextPosition() const { return velocity.apply(currPosition()); }
private:
    Rectangle rect;
    MovementVector velocity;

    void                    increaseSpeed();
    static double           ballInitAngle();

public:
    std::vector<std::unique_ptr<ISprite>> getSprites() const override;
};


#endif //PONG_BALL_HPP
