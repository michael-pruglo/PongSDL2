#include "GameManager.hpp"
#include "../Config.hpp"

std::shared_ptr<GameManager> GameManager::_instance = nullptr;

std::shared_ptr<GameManager> GameManager::getInstance(IGame* game)
{
    if (_instance == nullptr)
        _instance = std::shared_ptr<GameManager> {new GameManager(game)};
    return _instance;
}

GameManager::GameManager(IGame *game) :
    game(game)
{
}

void GameManager::run()
{
    if (!mainWindow.init(game->getTitle(), config::SCREEN_WIDTH, config::SCREEN_HEIGHT))
        return;

    auto frameExpectedTime = 1000/config::FPS;
    while (mainWindow.isOpen())
    {
        auto frameBegin = SDL_GetTicks();

        processFrame();

        auto frameRealTime = SDL_GetTicks() - frameBegin;
        if (frameRealTime < frameExpectedTime)
            SDL_Delay(frameExpectedTime-frameRealTime);
    }
}

void GameManager::processFrame()
{
    mainWindow.handleEvents(game->getInputManager());
    game->updateGameLogic();
    mainWindow.render(game->getRenderedEntities());
}
