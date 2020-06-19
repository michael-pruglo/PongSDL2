#ifndef PONG_MOVEMENTVECTOR_HPP
#define PONG_MOVEMENTVECTOR_HPP

#include <cmath>
#include "Position.hpp"

struct MovementVector
{
    double angle; //radians
    double len;

    Position apply(Position pos) const { return Position{pos.getX()+std::cos(angle)*len, pos.getY()-std::sin(angle)*len}; }
};


#endif //PONG_MOVEMENTVECTOR_HPP
