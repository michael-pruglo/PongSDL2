#ifndef PONG_GAMEWINDOW_HPP
#define PONG_GAMEWINDOW_HPP

#include <vector>
#include "SDL.h"
#include "SDL_ttf.h"
#include "../controller/IRenderable.hpp"
#include "../controller/IInputManager.hpp"

class GameWindow
{
public:
         ~GameWindow();
    bool init(const std::string& title, int width, int height);
    void handleEvents(IInputManager& inputManager);
    void render(const std::vector<IRenderable*>& itemsToRender) const;

    bool isOpen() const { return open; }

private:
    bool open = true;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};


#endif //PONG_GAMEWINDOW_HPP
