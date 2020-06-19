#ifndef PONG_IGAME_HPP
#define PONG_IGAME_HPP

#include <vector>
#include "IInputManager.hpp"

class IGame
{
public:
    virtual std::string                 getTitle() const = 0;
    virtual std::vector<IRenderable*>   getRenderedEntities() = 0;
    virtual IInputManager&              getInputManager() = 0;

    virtual void                        updateGameLogic() = 0;
};


#endif //PONG_IGAME_HPP
