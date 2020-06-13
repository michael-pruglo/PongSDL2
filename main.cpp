#include "Game.hpp"

int main(int argc, char* argv[])
{
    auto game = Game::getInstance();
    if (!game->init("Pong", 640, 480))
        return 1;

    while (!game->isTerminated())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    return 0;
}
