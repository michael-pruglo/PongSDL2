#ifndef PONG_IRENDERABLE_HPP
#define PONG_IRENDERABLE_HPP

#include <vector>
#include <memory>
#include "ISprite.hpp"

class IRenderable
{
public:
    virtual std::vector<std::unique_ptr<ISprite>> getSprites() const = 0;
};


#endif //PONG_IRENDERABLE_HPP
