#include "Pong.hpp"
#include "../utility/Logger.hpp"
#include "../utility/CollisionDetector.hpp"

Pong::Pong(Pong::GameMode mode) :
    gameMode(mode),
    player1(std::shared_ptr<PongPlayer>{new PongPlayer("Player1", Position(config::LEFT_PADDLE_X,  config::PADDLE_START_Y))}),
    player2(mode==GameMode::PLAYER_VS_PLAYER ?
            std::shared_ptr<PongPlayer>{new PongPlayer("Player2", Position(config::RIGHT_PADDLE_X, config::PADDLE_START_Y))} :
            std::shared_ptr<PongPlayer>{new PongBot   ("Bot",     Position(config::RIGHT_PADDLE_X, config::PADDLE_START_Y))}),
    inputManager(this)
{
    Logger::logMessage("Pong game initialized in mode PLAYER_VS_", (mode==GameMode::PLAYER_VS_PLAYER?"PLAYER":"BOT"));
}

std::vector<IRenderable *> Pong::getRenderedEntities()
{
    return {player1.get(), player2.get(), &ball};
}

void Pong::updateGameLogic()
{
    ball.update();
    player1->update();
    player2->update(ball.currPosition(), ball.getVelocityVector());

    handleCollisions();

    if (ball.currPosition().getX() < config::SCORELINE_X)
    {
        player2->increaseScore();
        Logger::logMessage(player2->getName(), " scored! ", player1->getScore(), " - ", player2->getScore());
        ball = Ball();
    }
    if (ball.currPosition().getX() > config::SCREEN_WIDTH - config::SCORELINE_X)
    {
        player1->increaseScore();
        Logger::logMessage(player1->getName(), " scored! ", player1->getScore(), " - ", player2->getScore());
        ball = Ball();
    }
}

void Pong::handleCollisions()
{
    Rectangle screenBottom(config::SCREEN_WIDTH, 0, Position(0, config::SCREEN_HEIGHT)),
                 screenTop(config::SCREEN_WIDTH, 0, Position(0, 0));

    //paddles not going off screen
    if (CollisionDetector::rectCollide(player1->getPaddle(), screenTop))
        player1->getPaddle().moveTo(Position(config::LEFT_PADDLE_X, 0));
    else if (CollisionDetector::rectCollide(player1->getPaddle(), screenBottom))
        player1->getPaddle().moveTo(Position(config::LEFT_PADDLE_X, config::SCREEN_HEIGHT-config::PADDLE_HEIGHT));
    if (CollisionDetector::rectCollide(player2->getPaddle(), screenTop))
        player2->getPaddle().moveTo(Position(config::RIGHT_PADDLE_X, 0));
    else if (CollisionDetector::rectCollide(player2->getPaddle(), screenBottom))
        player2->getPaddle().moveTo(Position(config::RIGHT_PADDLE_X, config::SCREEN_HEIGHT-config::PADDLE_HEIGHT));

    //ball collisions
    for (const auto& wall: {screenTop, player1->getPaddle(), player2->getPaddle()})
    {
        if (CollisionDetector::updateAfterCollidingUp(ball, wall))
            return;
    }
    for (const auto& wall: {screenBottom, player1->getPaddle(), player2->getPaddle()})
    {
        if (CollisionDetector::updateAfterCollidingDown(ball, wall))
            return;
    }
    if (CollisionDetector::updateAfterCollidingLeft(ball, player1->getPaddle()))
        return;
    if (CollisionDetector::updateAfterCollidingRight(ball, player2->getPaddle()))
        return;
}

void PongInputManager::handleKeyPress(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_UP:   if(pong->gameMode==Pong::GameMode::PLAYER_VS_PLAYER) pong->player2->startUp(); break;
        case SDLK_DOWN: if(pong->gameMode==Pong::GameMode::PLAYER_VS_PLAYER) pong->player2->startDown(); break;
        case SDLK_w:    pong->player1->startUp(); break;
        case SDLK_s:    pong->player1->startDown(); break;
    }
}

void PongInputManager::handleKeyUp(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_UP:   if(pong->gameMode==Pong::GameMode::PLAYER_VS_PLAYER) pong->player2->finishUp(); break;
        case SDLK_DOWN: if(pong->gameMode==Pong::GameMode::PLAYER_VS_PLAYER) pong->player2->finishDown(); break;
        case SDLK_w:    pong->player1->finishUp(); break;
        case SDLK_s:    pong->player1->finishDown(); break;
    }
}
