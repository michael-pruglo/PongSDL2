#ifndef PONG_RANDOM_HPP
#define PONG_RANDOM_HPP

#include <random>

class Random
{
    static std::mt19937 rng;

public:
    static int getInt(int low, int high);
    static double getAngleInRadians(int lowInDegrees, int highInDegrees);
};

#endif //PONG_RANDOM_HPP
