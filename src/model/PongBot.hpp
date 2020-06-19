#ifndef PONG_PONGBOT_HPP
#define PONG_PONGBOT_HPP

#include "PongPlayer.hpp"

class PongBot : public PongPlayer
{
public:
    explicit    PongBot(std::string name = "", Position position = Position()) : PongPlayer(name, position) {}
    void        update(Position ballPosition, MovementVector ballVelocity) override;

private:
    double      botY;
    const int   deltaPixels = config::PADDLE_SPEED+1;

    void        meetTarget(double y);
};

#endif //PONG_PONGBOT_HPP
