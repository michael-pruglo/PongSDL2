#ifndef PONG_RECTANGLE_HPP
#define PONG_RECTANGLE_HPP


#include "Position.hpp"

class Rectangle
{
public:
    explicit        Rectangle(int width = 0, int height = 0, Position position = Position()) :
                        w(width), h(height), pos(position)
                    {}
                    Rectangle(Position topLeft, Position bottomRight) :
                        Rectangle(bottomRight.getX()-topLeft.getX(), bottomRight.getY()-topLeft.getY(), topLeft)
                    {}

    inline Position position() const { return topLeft(); }
    inline Position topLeft() const     { return pos; }
    inline Position topRight() const    { return Position(pos.getX()+w, pos.getY()); }
    inline Position bottomLeft() const  { return Position(pos.getX(),   pos.getY()+h); }
    inline Position bottomRight() const { return Position(pos.getX()+w, pos.getY()+h); }
    inline void     move(Position::value_t dx, Position::value_t dy) { pos.move(dx, dy); }
    inline void     moveTo(Position position) { pos = position; }
    inline int      width() const { return w; }
    inline int      height() const { return h; }
private:
    Position pos;
    int w, h;
};


#endif //PONG_RECTANGLE_HPP
