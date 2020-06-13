#ifndef PONG_GAME_HPP
#define PONG_GAME_HPP

#include <memory>
#include <SDL2/SDL.h>

class Game
{
    static std::shared_ptr<Game> _instance;
    Game() = default;
public:
    Game(Game& other) = delete;
    void operator=(const Game& other) = delete;
    static std::shared_ptr<Game> getInstance();

public:
    ~Game();

    bool init(const std::string& title, int width, int height);

    void handleEvents();
    void update();
    void render();

    bool isTerminated() const { return terminated; }

private:
    bool terminated = false;
    SDL_Window* mainWindow = nullptr;
    SDL_Renderer* renderer = nullptr;
};


#endif //PONG_GAME_HPP
