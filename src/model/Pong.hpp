#ifndef PONG_PONG_HPP
#define PONG_PONG_HPP

#include <memory>
#include "Ball.hpp"
#include "PongPlayer.hpp"
#include "../controller/IGame.hpp"
#include "../controller/IInputManager.hpp"
#include "PongBot.hpp"

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
    enum class GameMode { PLAYER_VS_PLAYER, PLAYER_VS_BOT };
public:
                                Pong(GameMode mode = GameMode::PLAYER_VS_PLAYER);
    std::string                 getTitle() const override { return "Pong"; }
    std::vector<IRenderable*>   getRenderedEntities() override;
    IInputManager&              getInputManager() override { return inputManager; }
    void                        updateGameLogic() override;
private:
    GameMode gameMode;
    std::shared_ptr<PongPlayer> player1, player2;
    Ball ball;

    void                        handleCollisions();

    friend class PongInputManager;
    PongInputManager inputManager;
};


#endif //PONG_PONG_HPP
