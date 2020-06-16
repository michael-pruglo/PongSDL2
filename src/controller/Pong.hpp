#ifndef PONG_PONG_HPP
#define PONG_PONG_HPP

#include <memory>
#include "../view/GameWindow.hpp"
#include "../model/Ball.hpp"
#include "../model/Player.hpp"

class Pong
{
public:
    void run();

private:
    void update();

    Player player1, player2;
    Ball ball;
    GameWindow mainWindow;
    std::vector<std::unique_ptr<IRenderable>> renderedEntities;



    //class Pong is a singleton
private:
    static std::shared_ptr<Pong> _instance;
    Pong();
public:
    Pong(Pong& other) = delete;
    void operator=(const Pong& other) = delete;
    static std::shared_ptr<Pong> getInstance();
};


#endif //PONG_PONG_HPP
