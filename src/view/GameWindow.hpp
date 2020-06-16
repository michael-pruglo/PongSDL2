#ifndef PONG_GAMEWINDOW_HPP
#define PONG_GAMEWINDOW_HPP

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "IRenderable.hpp"

class GameWindow
{
public:
    ~GameWindow();
    bool init(const std::string& title, int width, int height);
    void handleEvents();
    void render(const std::vector<std::unique_ptr<IRenderable>>& itemsToRender) const;
    void renderSprite(const Sprite& sprite) const;

    bool isOpen() const { return open; }

private:
    bool open = true;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};


#endif //PONG_GAMEWINDOW_HPP
