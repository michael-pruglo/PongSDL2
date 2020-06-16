#include "Pong.hpp"
#include "../Config.hpp"

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
                               (config::SCREEN_HEIGHT-config::PADDLE_HEIGHT)/2.)) //middle of the screen
{
    renderedEntities.push_back(std::unique_ptr<IRenderable>(&player1));
    renderedEntities.push_back(std::unique_ptr<IRenderable>(&player2));
    renderedEntities.push_back(std::unique_ptr<IRenderable>(&ball));
}

void Pong::run()
{
    if (!mainWindow.init("Pong", config::SCREEN_WIDTH, config::SCREEN_HEIGHT))
        return;

    while (mainWindow.isOpen())
    {
        mainWindow.handleEvents();
        update();
        mainWindow.render(renderedEntities);
    }
}

void Pong::update()
{

}



