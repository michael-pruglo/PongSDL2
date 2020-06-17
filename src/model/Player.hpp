#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP

#include <string>
#include "../view/IRenderable.hpp"
#include "../utility/Position.hpp"
#include "../Config.hpp"
#include "../utility/Rectangle.hpp"

class Player : public IRenderable //TODO: rename to PongPlayer
{
public:
    explicit            Player(std::string name = "", Position position = Position()) : nm(std::move(name)), paddle(config::PADDLE_WIDTH, config::PADDLE_HEIGHT, position) {}

    inline std::string  getName() const { return nm; }
    inline int          getScore() const { return score; }
private:
    inline void         increaseScore() { ++score; }
    inline Rectangle&   getPaddle() { return paddle; }
    inline void         update() { paddle.move(0, paddleVelocity*config::PADDLE_SPEED); }
    inline void         startUp() { --paddleVelocity; }
    inline void         finishUp() { ++paddleVelocity; }
    inline void         startDown() { ++paddleVelocity; }
    inline void         finishDown() { --paddleVelocity; }
private:
    std::string nm;
    int score = 0;
    Rectangle paddle;
    int paddleVelocity = 0;

public:
    friend class Pong;
    friend class PongInputManager;
public:
    std::vector<Sprite> getSprites() const override
    {
        return {
            Sprite(nm, Position(config::SCREEN_WIDTH/4., 10)),
            Sprite(std::to_string(score), Position(config::SCREEN_WIDTH/4., 50)),
            Sprite(paddle)
        };
    }
};


#endif //PONG_PLAYER_HPP
