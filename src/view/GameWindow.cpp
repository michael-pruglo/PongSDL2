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

    //TODO: Init TTF here as well

    return success = true;
}

void GameWindow::handleEvents(IInputManager& inputManager)
{
    for (SDL_Event event ; SDL_PollEvent(&event); )
    {
        if (event.type == SDL_QUIT)
            open = false;
        else if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
            inputManager.handleKeyPress(event.key.keysym.sym);
        else if (event.type == SDL_KEYUP && event.key.repeat == 0)
            inputManager.handleKeyUp(event.key.keysym.sym);
    }
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    Logger::logMessage("GameWindow object destroyed.");
}

void GameWindow::render(const std::vector<IRenderable*>& itemsToRender) const
{
    SDL_RenderClear(renderer);
    for (const auto& entity: itemsToRender)
    {
        for (const auto& sprite: entity->getSprites())
            sprite->render(renderer);
    }
    SDL_RenderPresent(renderer);
}
