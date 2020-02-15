#include "Game.h"
#include <cstdio>
#include "Text.h"

Text::Text(int fontSize, const char* text)
{
	_fontColor = { 255, 255, 255, 255 };
	_fontPath = "Assets/Fonts/8BIT.ttf";
	_fontSize = fontSize;
	_fontValue = text;

	_textTexture = loadFont(_fontPath, _fontSize, _fontValue, _fontColor);
	SDL_QueryTexture(_textTexture, NULL, NULL, &_textRect.w, &_textRect.h);
}

Text::~Text()
{

}

SDL_Texture* Text::loadFont(const char* fontPath, int fontSize, const char* text, const SDL_Color& color)
{
	TTF_Font* font = TTF_OpenFont(fontPath, fontSize);
	if (!font)
	{
		printf("Error loading font. Error: %s\n", TTF_GetError());
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	if (!textSurface)
	{
		printf("Error creating text surface: %s\n", SDL_GetError());
	}

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(Gunngine::renderer, textSurface);
	if (!Texture)
	{
		printf("Error creating text texture: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(textSurface);

	TTF_CloseFont(font);

	return Texture;
}

void Text::draw(int x, int y) const
{
	_textRect.x = x;
	_textRect.y = y;

	SDL_RenderCopy(Gunngine::renderer, _textTexture, nullptr, &_textRect);
}

void Text::setText(const char* newText)
{
	_fontValue = newText;
}

//void Text::update()
//{
//	_textSurface = TTF_RenderText_Solid(_textFont, text, color);
//	if (!textSurface)
//	{
//		printf("Error creating text surface: %s\n", SDL_GetError());
//	}
//
//	_Texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	if (!Texture)
//	{
//		printf("Error creating text texture: %s\n", SDL_GetError());
//	}
//
//	SDL_FreeSurface(textSurface);
//}