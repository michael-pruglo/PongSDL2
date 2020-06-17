#include "model/Pong.hpp"
#include "controller/GameManager.hpp"

int main(int argc, char* argv[])
{
    Pong pong;
    GameManager::getInstance(&pong)->run();
    return 0;
}
