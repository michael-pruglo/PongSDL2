#include "Game.hpp"
#include "utility/Logger.hpp"

std::shared_ptr<Game> Game::_instance = nullptr;

std::shared_ptr<Game> Game::getInstance()
{
    if (_instance == nullptr)
        _instance = std::shared_ptr<Game> {new Game()};
    return _instance;
}

bool Game::init(const std::string& title, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::logError("Cannot init Game. Error: ", SDL_GetError());
        return false;
    }
    Logger::logMessage("SDL subsystems initialized.");

    mainWindow = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  SDL_WINDOW_SHOWN);
    if (!mainWindow)
    {
        Logger::logError("Cannot create the main window. Error: ", SDL_GetError());
        return false;
    }
    Logger::logMessage("Main window created.");

    renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        Logger::logError("Cannot create renderer for the main window. Error: ", SDL_GetError());
        return false;
    }
    Logger::logMessage("Renderer created.");
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    return true;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            terminated = true;
            break;
        default:
//            Logger::logError("Unrecognized event happened! Event type = ", event.type);
            break;
    }
}

void Game::update()
{

}

void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    Logger::logMessage("Game object destroyed.");
}