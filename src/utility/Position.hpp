#ifndef PONG_POSITION_HPP
#define PONG_POSITION_HPP


class Position
{
public:
    typedef double value_t;
    explicit Position(value_t x = 0, value_t y = 0) : xpos(x), ypos(y) {}

    void move(value_t dx, value_t dy) { xpos+=dx; ypos+=dy; }
    void set(value_t x, value_t y) { xpos=x; ypos=y; }
    value_t getX() const { return xpos; }
    value_t getY() const { return ypos; }

private:
    value_t xpos, ypos;
};


#endif //PONG_POSITION_HPP
