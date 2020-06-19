#include "TextSprite.hpp"
#include "../utility/Logger.hpp"
#include "../Config.hpp"

TextSprite::TextSprite(std::string text, int size, Position position, SDL_Color color) :
    txt(std::move(text)),
    pos(position),
    col(color)
{
    font = TTF_OpenFont(config::FONT_FILENAME.c_str(), size);
    if (!font)
        Logger::logError("Cannot open font \"", config::FONT_FILENAME, "\"");
}

void TextSprite::render(SDL_Renderer *renderer) const
{
    auto textSurface = TTF_RenderText_Solid(font, txt.c_str(), col);
    auto texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect position{(int)pos.getX(), (int)pos.getY(), w, h};
    SDL_RenderCopy(renderer, texture, NULL, &position);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(texture);
}
