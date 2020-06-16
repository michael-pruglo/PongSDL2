#include "GameWindow.hpp"
#include "../utility/Logger.hpp"

bool GameWindow::init(const std::string& title, int width, int height)
{
    bool success;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::logError("Cannot init \"", title, "\" window. Error: ", SDL_GetError());
        return success = false;
    }
    Logger::logMessage("SDL subsystems initialized.");

    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);
    if (!window)
    {
        Logger::logError("Cannot create \"", title, "\" window. Error: ", SDL_GetError());
        return success = false;
    }
    Logger::logMessage("\"", title, "\" window created.");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        Logger::logError("Cannot create renderer for \"", title, "\" window. Error: ", SDL_GetError());
        return success = false;
    }
    Logger::logMessage("The renderer for \"", title, "\" window created.");

    return success = true;
}

void GameWindow::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                open = false;
                break;
        }

    }
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    Logger::logMessage("GameWindow object destroyed.");
}

void GameWindow::render(const std::vector<std::unique_ptr<IRenderable>>& itemsToRender) const
{
    SDL_RenderClear(renderer);
    for (const auto& entity: itemsToRender)
    {
        for (const auto& sprite: entity->getSprites())
            renderSprite(sprite);
    }
    SDL_RenderPresent(renderer);
}

void GameWindow::renderSprite(const Sprite& sprite) const
{

}
