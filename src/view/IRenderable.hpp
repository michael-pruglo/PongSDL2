#ifndef PONG_IRENDERABLE_HPP
#define PONG_IRENDERABLE_HPP

#include <vector>
#include "Sprite.hpp"

class IRenderable
{
public:
    virtual std::vector<Sprite> getSprites() const = 0;
};


#endif //PONG_IRENDERABLE_HPP
