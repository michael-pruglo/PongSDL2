# PongSDL2
Classic Pong using SDL2. <p><p>

###Getting started
Just launch Pong.exe. <p>
There are two modes of playing available: "player vs player" or "player vs bot".
The former is the default mode.
To activate the latter, you can pass a command line argument "`BOT`": 
```
> Pong.exe BOT
```
#####Additional info:
The project was built and compiled using SDL2 v2.0.12, SDL2_ttf v2.0.15 and MinGW for Windows x64.
<p><p><p>

###Requirements:
- [x] use only SDL2
- [x] implement a game bot
- [x] provide a README overview file

1. <h5>Demonstrate C++ knowledge (not C)</h5> 
     variadic templates : `utility/Logger.hpp`
     shared_ptr : `GameManager::_instance`, `Pong::player`
     `auto[dx, dy]` : `Collision Detector`
     random 
2. <h5>Demonstrate OOP knowledge and the ability to use it</h5>
     dd
3. <h5>Demonstrate the ability to use STL</h5>
     The needs of my project regarding STL don't go much further than `std::vector` and `std::pair`.
4. <h5>Neatly structured code</h5>
     The classes of the project are divided according to the Model-View-Controller pattern, conveniently separated into categorical folders.\
     Alongside them, there is a group of helper classes in "/utility/".
5. <h5>Demonstrate the ability to include and use external libraries</h5>
     The project uses SDL2 and SDL2_ttf libraries. It also makes it possible to easily include SDL2_image and SDL2_mixer.\
     The libraries are linked with automatic scripts.\
     See CMakeLists.txt for details.
6. <h5>Demonstrate familiarity with the architecture of game engines</h5>
     Class `controller/GameManager` provides a wrapper around (any) game. `GameManager::run()` describes the main game loop:
     ```c++
    while (mainWindow.isOpen())
    {
            ...   
            processFrame();
            ...
    }
    ...
    void GameManager::processFrame()
    {
        mainWindow.handleEvents(game->getInputManager());
        game->updateGameLogic();
        mainWindow.render(game->getRenderedEntities());
    }
    ```
   Class `view/GameWindow` handles the graphical tasks specifically. It initializes and frees resources in it's constructor/destructor, 
   polls the event queue, and implements the update of the double-buffered renderer.
7. <h5>Apply some of Design Patterns (not only a Singleton)</h5>
     GameManager is a singleton, Factory: IGame creates IInputManagers, Factory2: IRenderable derives Ball and PongPlayer, who construct ISprite
     Controllers are a kind of Mediator, MVC
8. <h5>The code has to compile under Win32, Ubuntu 16.04 x64 or 18.04 x64 or it has to be run with an executable file.</h5>
     The game can be started by running `Pong.exe [BOT]`. 
