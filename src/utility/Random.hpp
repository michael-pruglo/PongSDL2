#ifndef PONG_RANDOM_HPP
#define PONG_RANDOM_HPP

#include <random>

class Random
{
    static std::random_device dev;
    static std::mt19937 rng;

public:
    static int getInt(int low, int high);
    static double getAngleInRadians();
};

#endif //PONG_RANDOM_HPP
