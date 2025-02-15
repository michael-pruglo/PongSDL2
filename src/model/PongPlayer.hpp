#ifndef PONG_PONGPLAYER_HPP
#define PONG_PONGPLAYER_HPP

#include <string>
#include "../controller/IRenderable.hpp"
#include "../Config.hpp"
#include "../utility/Position.hpp"
#include "../utility/Rectangle.hpp"
#include "../utility/MovementVector.hpp"
#include "../view/TextSprite.hpp"
#include "../view/RectSprite.hpp"

class PongPlayer : public IRenderable
{
public:
    explicit            PongPlayer(std::string name = "", Position position = Position());

    inline std::string  getName() const { return nm; }
    inline int          getScore() const { return score; }

protected:
    inline void         increaseScore() { ++score; }
    inline Rectangle&   getPaddle() { return paddle; }
    inline void         update() { paddle.move(0, paddleVelocity*config::PADDLE_SPEED); }
    virtual void        update(Position ballPosition, MovementVector ballVelocity) { update(); }
    inline void         startUp() { --paddleVelocity; capVelocity(); }
    inline void         finishUp() { ++paddleVelocity; capVelocity(); }
    inline void         startDown() { ++paddleVelocity; capVelocity(); }
    inline void         finishDown() { --paddleVelocity; capVelocity(); }
    inline void         stop() { paddleVelocity = 0; }
    inline bool         isLeft() const { return paddle.position().getX()==config::LEFT_PADDLE_X; }

private:
    inline void         capVelocity() { if (paddleVelocity<-1) paddleVelocity=-1; else if (paddleVelocity>1) paddleVelocity=1; }
protected:
    std::string nm;
    int score = 0;
    Rectangle paddle;
    int paddleVelocity = 0;

public:
    friend class Pong;
    friend class PongInputManager;
public:
    std::vector<std::unique_ptr<ISprite>> getSprites() const override;
};


#endif //PONG_PONGPLAYER_HPP
