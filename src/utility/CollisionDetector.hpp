#ifndef PONG_COLLISIONDETECTOR_HPP
#define PONG_COLLISIONDETECTOR_HPP

#include "Rectangle.hpp"
#include "../model/Ball.hpp"

class CollisionDetector
{
public:
    static bool rectCollide(const Rectangle& rect1, const Rectangle& rect2);
    static bool updateAfterCollidingUp(Ball& ball, const Rectangle& wall);
    static bool updateAfterCollidingDown(Ball& ball, const Rectangle& wall);
    static bool updateAfterCollidingLeft(Ball& ball, const Rectangle& wall);
    static bool updateAfterCollidingRight(Ball& ball, const Rectangle& wall);

private:
    static bool willCollideHorizontal(Position crucial1, Position crucial2,
                                      Position::value_t dx, Position::value_t dy,
                                      Position::value_t horLineX1, Position::value_t horLineX2, Position::value_t horLineY);
    static bool willCollideVertical(Position crucial1, Position crucial2,
                                    Position::value_t dx, Position::value_t dy,
                                    Position::value_t verLineY1, Position::value_t verLineY2, Position::value_t verLineX);
};


#endif //PONG_COLLISIONDETECTOR_HPP
