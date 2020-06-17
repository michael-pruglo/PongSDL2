#ifndef PONG_INPUT_HPP
#define PONG_INPUT_HPP

#include <unordered_set>
#include <SDL2/SDL.h>
#include <sstream>

class Input
{
public:
    bool keyPressed(SDL_Scancode code) const { return keyboardState[code]; }
    std::string show() const { std::stringstream ss; for (auto& x: keyboardState) ss<<x<<", "; return ss.str(); }
private:
    const uint8_t* keyboardState;
    int keyboardSize;
};


#endif //PONG_INPUT_HPP
