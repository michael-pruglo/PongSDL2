#include "Random.hpp"

std::mt19937 Random::rng = std::mt19937(std::random_device()());

int Random::getInt(int low, int high)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(low, high);
    return dist(rng);
}

double Random::getAngleInRadians(int lowInDegrees, int highInDegrees)
{
    return getInt(lowInDegrees, highInDegrees)*M_PI/180;
}

