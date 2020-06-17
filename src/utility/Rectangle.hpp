#ifndef PONG_RECTANGLE_HPP
#define PONG_RECTANGLE_HPP


#include "Position.hpp"

class Rectangle
{
public:
    explicit        Rectangle(int width = 0, int height = 0, Position position = Position());
                    Rectangle(Position topLeft, Position bottomRight);

    inline Position position() const { return pos; }
    inline Position bottomRight() const { return Position(pos.getX()+w, pos.getY()+h); }
    inline void     move(Position::value_t dx, Position::value_t dy) { pos.move(dx, dy); }
    inline void     moveTo(Position position) { pos = position; }
    inline int      width() const { return w; }
    inline int      height() const { return h; }
private:
    Position pos;
    int w, h;
};

bool collide(const Rectangle& rect1, const Rectangle& rect2);


#endif //PONG_RECTANGLE_HPP
