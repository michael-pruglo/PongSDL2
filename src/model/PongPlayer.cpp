#include "PongPlayer.hpp"

PongPlayer::PongPlayer(std::string name, Position position) :
    nm(std::move(name)),
    paddle(config::PADDLE_WIDTH, config::PADDLE_HEIGHT, position)
{}

std::vector<std::unique_ptr<ISprite>> PongPlayer::getSprites() const
{
    //TODO: beautify
    std::vector<std::unique_ptr<ISprite>> res;
    res.push_back(std::unique_ptr<ISprite> {
            new TextSprite(nm,
                           config::NAME_FONT_SIZE,
                           Position(isLeft()?config::LEFT_NAME_X:config::RIGHT_NAME_X, config::NAME_Y),
                           {config::NAME_COLOR.r,config::NAME_COLOR.g,config::NAME_COLOR.b,config::NAME_COLOR.a})
    });
    res.push_back(std::unique_ptr<ISprite> {
            new TextSprite(std::to_string(score),
                           config::SCORE_FONT_SIZE,
                           Position((isLeft()?config::LEFT_NAME_X:config::RIGHT_NAME_X)+15, config::NAME_Y+config::NAME_FONT_SIZE+8),
                           {config::SCORE_COLOR.r,config::SCORE_COLOR.g,config::SCORE_COLOR.b,config::SCORE_COLOR.a})
    });
    res.push_back(std::unique_ptr<ISprite> {
            new RectSprite(paddle,
                           {config::PADDLE_COLOR.r,config::PADDLE_COLOR.g,config::PADDLE_COLOR.b,config::PADDLE_COLOR.a})
    });
    return res;
}