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
}