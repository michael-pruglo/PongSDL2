#include <cassert>
#include <iostream>
#include "model/Pong.hpp"
#include "controller/GameManager.hpp"

#include "utility/CollisionDetector.hpp"

int main(int argc, char* argv[])
{
    Pong pong;
    GameManager::getInstance(&pong)->run();
    return 0;
}
