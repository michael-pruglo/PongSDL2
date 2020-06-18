#ifndef PONG_IINPUTMANAGER_HPP
#define PONG_IINPUTMANAGER_HPP

#include "SDL_keycode.h"

class IInputManager
{
public:
    virtual void handleKeyPress(SDL_Keycode keycode) = 0;
    virtual void handleKeyUp(SDL_Keycode keycode) = 0;
};


#endif //PONG_IINPUTMANAGER_HPP
