#include "Player.hpp"

Player::Player(const std::string& name, Position position) :
    nm(name),
    paddle(config::PADDLE_WIDTH, config::PADDLE_HEIGHT, position)
{
}

void Player::update()
{
    paddle.move(0, paddleVelocity * config::PADDLE_SPEED);
}

std::vector<Sprite> Player::getSprites() const
{
    return {
        Sprite(nm),
        Sprite(paddle)
    };
}