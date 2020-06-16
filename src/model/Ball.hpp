#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include "../view/IRenderable.hpp"
#include "../utility/Position.hpp"
#include "../Config.hpp"
#include "../utility/Rectangle.hpp"

class Ball : public IRenderable
{
public:
    inline void     move(Position::value_t dx, Position::value_t dy);
    inline Position position() const { return rect.position(); }
private:
    Rectangle rect = Rectangle(config::BALL_SIZE, config::BALL_SIZE);


public:
    std::vector<Sprite> getSprites() const override;
};


#endif //PONG_BALL_HPP
