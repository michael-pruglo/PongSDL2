#include "Pong.hpp"

Pong::Pong() :
    player1("Player1", Position(config::PADDLE_X,
                                config::SCREEN_CENTER_Y-config::PADDLE_HEIGHT/2.)), //middle of the screen

    player2("Player2", Position(config::SCREEN_WIDTH-config::PADDLE_X-config::PADDLE_WIDTH,
                                config::SCREEN_CENTER_Y-config::PADDLE_HEIGHT/2.)), //middle of the screen

    ball(Position(config::SCREEN_CENTER_X-config::BALL_SIZE/2.,
                  config::SCREEN_CENTER_Y-config::BALL_SIZE/2.)),

    inputManager(this)
{
}

std::vector<IRenderable *> Pong::getRenderedEntities()
{
    return {&player1, &player2, &ball};
}

void Pong::updateGameLogic()
{
    player1.update();
    player2.update();
    ball.move(1,1);
}





void PongInputManager::handleKeyPress(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_UP:   pong->player2.startUp(); break;
        case SDLK_DOWN: pong->player2.startDown(); break;
        case SDLK_w:    pong->player1.startUp(); break;
        case SDLK_s:    pong->player1.startDown(); break;
    }
}

void PongInputManager::handleKeyUp(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_UP:   pong->player2.finishUp(); break;
        case SDLK_DOWN: pong->player2.finishDown(); break;
        case SDLK_w:    pong->player1.finishUp(); break;
        case SDLK_s:    pong->player1.finishDown(); break;
    }
}
