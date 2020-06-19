# PongSDL2
classic Pong using SDL2

1) variadic templates : `utility/Logger.hpp`
shared_ptr : `GameManager::_instance`, `Pong::player`
`auto[dx, dy]` : `Collision Detector`
random
2)
3)
4)
5)
6)
7) GameManager is a singleton, Factory: IGame creates IInputManagers, Factory2: IRenderable derives Ball and PongPlayer, who construct ISprite
Controllers are a kind of Mediator

RenderableEntity derived from Entity 