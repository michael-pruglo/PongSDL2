#include "Rectangle.hpp"

Rectangle::Rectangle(int width, int height, Position position) :
    pos(position),
    w(width),
    h(height)
{
}

Rectangle::Rectangle(Position topLeft, Position bottomRight) :
    Rectangle(bottomRight.getX()-topLeft.getX(),
            bottomRight.getY()-topLeft.getY(),
            topLeft)
{
}

bool collide(const Rectangle& rect1, const Rectangle& rect2)
{
    //TODO: implement collisions
    Position::value_t   left1   = rect1.position().getX(),
                        top1    = rect1.position().getY(),
                        right1  = rect1.bottomRight().getX(),
                        bottom1 = rect1.bottomRight().getY();
    Position::value_t   left2   = rect2.position().getX(),
                        top2    = rect2.position().getY(),
                        right2  = rect2.bottomRight().getX(),
                        bottom2 = rect2.bottomRight().getY();

    return left1<=right2 && right1>=left2 && top1<=bottom2 && bottom1>=top2;
}