#include <string>
#include "model/Pong.hpp"
#include "controller/GameManager.hpp"

int main(int argc, char* argv[])
{
    Pong pong(argc>1 && std::string(argv[1]) == "BOT" ?
            Pong::GameMode::PLAYER_VS_BOT :
            Pong::GameMode::PLAYER_VS_PLAYER);

    GameManager::getInstance(&pong)->run();

    return 0;
}
