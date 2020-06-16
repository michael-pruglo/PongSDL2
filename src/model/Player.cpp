#include "Player.hpp"

Player::Player(const std::string& name, Position position) :
    nm(name),
    paddle(config::PADDLE_WIDTH, config::PADDLE_HEIGHT, position)
{
}

void Player::moveUp(Position::value_t val)
{
    paddle.move(0, -val);
}

void Player::moveDown(Position::value_t val)
{
    paddle.move(0, val);
}

std::vector<Sprite> Player::getSprites() const
{
    return {
        Sprite(nm),
        Sprite(paddle)
    };
}