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
<ol>
  <li> <h5>Demonstrate C++ knowledge (not C)</h5> 
  variadic templates : `utility/Logger.hpp`
  shared_ptr : `GameManager::_instance`, `Pong::player`
  `auto[dx, dy]` : `Collision Detector`
  random
  </li>
  
  <li> <h5>Demonstrate OOP knowledge and the ability to use it</h5>
  dd
  </li>
  
  <li> <h5>Demonstrate the ability to use STL</h5>
  dd
  </li>
  
  <li> <h5>Neatly structured code</h5>
  dd
  </li>
  
  <li> <h5>Demonstrate the ability to include and use external libraries</h5>
  dd
  </li>
  
  <li> <h5>Demonstrate familiarity with the architecture of game engines</h5>
  dd
  </li>
  
  <li> <h5>Apply some of Design Patterns (not only a Singleton)</h5>
  GameManager is a singleton, Factory: IGame creates IInputManagers, Factory2: IRenderable derives Ball and PongPlayer, who construct ISprite
  Controllers are a kind of Mediator
  </li>
    
  <li> <h5>The code has to compile under Win32, Ubuntu 16.04 x64 or 18.04 x64 or it has to be run with an executable file.</h5>
  dd
  </li>
</ol>