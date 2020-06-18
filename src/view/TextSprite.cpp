#include "TextSprite.hpp"
#include "../utility/Logger.hpp"
#include "../Config.hpp"

TextSprite::TextSprite(std::string text, int size, Position position) :
    txt(std::move(text)),
    pos(position)
{
    if (TTF_Init() == -1)
        Logger::logError("could not init TTF", TTF_GetError());
    font = TTF_OpenFont(config::FONT_FILENAME.c_str(), size);
    if (font == nullptr)
        Logger::logError("Could not open font \"", config::FONT_FILENAME, "\"");
}

void TextSprite::render(SDL_Renderer *renderer) const
{
    auto textSurface = TTF_RenderText_Solid(font, txt.c_str(), {255,255,255});
    auto texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    Logger::logMessage(txt, " texture is of a size ", w, "x", h);

    SDL_Rect position{(int)pos.getX(), (int)pos.getY(), (int)pos.getX()+w, (int)pos.getY()+h};
    SDL_RenderCopy(renderer, texture, NULL, &position);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(texture);
}
