#ifndef PONG_GAMEMANAGER_HPP
#define PONG_GAMEMANAGER_HPP

#include <memory>
#include "IRenderable.hpp"
#include "../view/GameWindow.hpp"
#include "IGame.hpp"
#include "IInputManager.hpp"

class GameManager
{
public:
    void run();

private:
    void processFrame();

    IGame* game;
    GameWindow mainWindow;


    //class GameManager is a singleton
private:
    static std::shared_ptr<GameManager> _instance;
    GameManager(IGame* game);
public:
    GameManager(GameManager& other) = delete;
    void operator=(const GameManager& other) = delete;
    static std::shared_ptr<GameManager> getInstance(IGame* game);
};


#endif //PONG_GAMEMANAGER_HPP
