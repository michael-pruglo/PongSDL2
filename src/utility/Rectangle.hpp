#ifndef PONG_RECTANGLE_HPP
#define PONG_RECTANGLE_HPP


#include "Position.hpp"

class Rectangle
{
public:
    explicit        Rectangle(int width = 0, int height = 0, Position position = Position());
                    Rectangle(Position topLeft, Position bottomRight);

    inline Position position() const { return pos; }
    inline void     move(Position::value_t dx, Position::value_t dy) { pos.move(dx, dy); }
    inline int      width() const { return w; }
    inline int      height() const { return h; }
    friend bool     collide(const Rectangle& rect1, const Rectangle& rect2);
private:
    Position pos;
    int w, h;
};


#endif //PONG_RECTANGLE_HPP
