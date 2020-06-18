#include "Pong.hpp"
#include "../utility/Logger.hpp"

Pong::Pong() :
    player1("Player1", Position(config::LEFT_PADDLE_X, config::PADDLE_START_Y)),
    player2("Player2", Position(config::RIGHT_PADDLE_X, config::PADDLE_START_Y)),
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
    ball.update();

    handleCollisions();

    if (ball.currPosition().getX() < config::SCORELINE_X)
    {
        player2.increaseScore();
        Logger::logMessage(player2.getName(), " scored! ", player1.getScore(), " - ", player2.getScore());
        ball = Ball();
    }
    if (ball.currPosition().getX() > config::SCREEN_WIDTH - config::SCORELINE_X)
    {
        player1.increaseScore();
        Logger::logMessage(player1.getName(), " scored! ", player1.getScore(), " - ", player2.getScore());
        ball = Ball();
    }
}

void Pong::handleCollisions()
{
    //TODO: handle quick collisions
    if (   collide(player1.getPaddle(), ball.getRect())
        || collide(player2.getPaddle(), ball.getRect()))
    {
        ball.reflectX(); //TODO: bug with corner collisions - bugfix would be to separate vertical collisions, horizontal and diagonal collisions.
    }

    Rectangle screenBottom(config::SCREEN_WIDTH, 0, Position(0, config::SCREEN_HEIGHT)),
                 screenTop(config::SCREEN_WIDTH, 0, Position(0, 0));

    if (   collide(ball.getRect(), screenTop)
        || collide(ball.getRect(), screenBottom))
    {
        ball.reflectY();
    }


    if (collide(player1.getPaddle(), screenTop))
        player1.getPaddle().moveTo(Position(config::LEFT_PADDLE_X, 0));
    else if (collide(player1.getPaddle(), screenBottom))
        player1.getPaddle().moveTo(Position(config::LEFT_PADDLE_X, config::SCREEN_HEIGHT-config::PADDLE_HEIGHT));
    if (collide(player2.getPaddle(), screenTop))
        player2.getPaddle().moveTo(Position(config::RIGHT_PADDLE_X, 0));
    else if (collide(player2.getPaddle(), screenBottom))
        player2.getPaddle().moveTo(Position(config::RIGHT_PADDLE_X, config::SCREEN_HEIGHT-config::PADDLE_HEIGHT));
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
