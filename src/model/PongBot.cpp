#include "PongBot.hpp"
#include "../utility/Logger.hpp"

void PongBot::update(Position ballPosition, MovementVector ballVelocity)
{
    double ballY = ballPosition.getY()+config::BALL_SIZE/2.;
    botY = getPaddle().position().getY()+config::PADDLE_HEIGHT/2.;

    if (ballVelocity.angle>M_PI/2 && ballVelocity.angle<3*M_PI/2) //the ball goes away
    {
        //Logger::logMessage("Ball goes away...");
        meetTarget(config::SCREEN_HEIGHT/2.); //move towards center
    }
    else //the ball goes towards the bot
    {
        meetTarget(ballY);
    }


    PongPlayer::update();
}

void PongBot::meetTarget(double y)
{
    if (y > botY+deltaPixels)
    {
        startDown();
        Logger::logMessage("bot ", botY, " = [",botY-deltaPixels,",",botY+deltaPixels,"]  meeting target ", y, "    Bot decides to go down");
    }
    else if (y < botY-deltaPixels)
    {
        startUp();
        Logger::logMessage("bot ", botY, " = [",botY-deltaPixels,",",botY+deltaPixels,"]  meeting target ", y, "    Bot decides to go up");
    }
    else
        stop();
}

