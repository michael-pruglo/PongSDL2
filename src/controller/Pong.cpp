#include "Pong.hpp"
#include "../Config.hpp"
#include "../utility/Logger.hpp"

std::shared_ptr<Pong> Pong::_instance = nullptr;

std::shared_ptr<Pong> Pong::getInstance()
{
    if (_instance == nullptr)
        _instance = std::shared_ptr<Pong> {new Pong()};
    return _instance;
}

Pong::Pong() :
    player1("Player1", Position(config::PADDLE_X,
                               (config::SCREEN_HEIGHT-config::PADDLE_HEIGHT)/2.)), //middle of the screen

    player2("Player2", Position(config::SCREEN_WIDTH-config::PADDLE_X-config::PADDLE_WIDTH,
                               (config::SCREEN_HEIGHT-config::PADDLE_HEIGHT)/2.)), //middle of the screen

    renderedEntities({&player1, &player2, &ball})
{
}

void Pong::run()
{
    if (!mainWindow.init("Pong", config::SCREEN_WIDTH, config::SCREEN_HEIGHT))
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

void Pong::processFrame()
{
    std::vector<SDL_Keycode> pressedKeys;
    mainWindow.handleEvents(pressedKeys);
    update(pressedKeys);
    mainWindow.render(renderedEntities);
}

void Pong::update(const std::vector<SDL_Keycode>& pressedKeys)
{
    //TODO: multi-keypress
    for (auto key: pressedKeys)
    {
        //Logger::logMessage("\tkey ", key, " and SDLK_UP = ", SDLK_UP, " and SDLK_w = ", SDLK_w);
        switch (key)
        {
            case SDLK_UP:   player2.moveUp(); break;
            case SDLK_DOWN: player2.moveDown(); break;
            case SDLK_w:    player1.moveUp(); break;
            case SDLK_s:    player1.moveDown(); break;
        }
    }
    if (!pressedKeys.empty())
        Logger::logMessage("end of ", pressedKeys.size());

    ball.update();
}



