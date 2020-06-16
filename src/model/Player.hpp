#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP

#include <string>
#include "../view/IRenderable.hpp"
#include "../utility/Position.hpp"
#include "../Config.hpp"
#include "../utility/Rectangle.hpp"

class Player : public IRenderable
{
public:
    explicit    Player(const std::string& name = "", Position position = Position());
    std::string name() const { return nm; }
    Position    position() const { return paddle.position(); }
    int         width() const { return paddle.width(); }
    int         height() const { return paddle.height(); }
    void        moveUp(Position::value_t val = config::PADDLE_SPEED);
    void        moveDown(Position::value_t val = config::PADDLE_SPEED);
private:
    std::string nm;
    Rectangle paddle;

public:
    std::vector<Sprite> getSprites() const override;
};


#endif //PONG_PLAYER_HPP
