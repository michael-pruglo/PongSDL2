#ifndef PONG_PONG_HPP
#define PONG_PONG_HPP

#include <memory>
#include "Ball.hpp"
#include "Player.hpp"
#include "../controller/IGame.hpp"
#include "../controller/IInputManager.hpp"

class Pong;

class PongInputManager : public IInputManager
{
public:
    explicit    PongInputManager(Pong* pongInstance) : pong(pongInstance) {}
    void        handleKeyPress(SDL_Keycode keycode) override;
    void        handleKeyUp(SDL_Keycode keycode) override;
private:
    Pong* pong;
};

class Pong : public IGame
{
public:
                                Pong();
    std::string                 getTitle() const override { return "Pong"; }
    std::vector<IRenderable*>   getRenderedEntities() override;
    IInputManager&              getInputManager() override { return inputManager; }
    void                        updateGameLogic() override;
private:
    Player player1, player2;
    Ball ball;

    void                        handleCollisions();

    friend class PongInputManager;
    PongInputManager inputManager;
};



#endif //PONG_PONG_HPP
