#include "Random.hpp"

std::random_device Random::dev = std::random_device();
std::mt19937 Random::rng = std::mt19937(Random::dev());

int Random::getInt(int low, int high)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(low, high);
    return dist(rng);
}

double Random::getAngleInRadians()
{
    return getInt(0, 314)/100.; //TODO: beautify
}

