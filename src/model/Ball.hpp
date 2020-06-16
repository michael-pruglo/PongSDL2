#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include "../view/IRenderable.hpp"
#include "../utility/Position.hpp"
#include "../Config.hpp"
#include "../utility/Rectangle.hpp"

class Ball : public IRenderable
{
public:
    explicit        Ball(Position pos = Position());
    void            move(Position::value_t dx, Position::value_t dy);
    inline void     update() { move(xVelocity, yVelocity); }
    inline Position position() const { return rect.position(); }
private:
    Rectangle rect;
    double xVelocity, yVelocity;


public:
    std::vector<Sprite> getSprites() const override;
};


#endif //PONG_BALL_HPP
