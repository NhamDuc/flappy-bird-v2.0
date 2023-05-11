#include "Text.h"

void Text::CreateFont(const char* path, int size)
{
    font = TTF_OpenFont(path, size);
    if(!font)
    {
        cout << TTF_GetError() << endl;
    }
}

void Text::TXT(string s, int r, int g, int b, SDL_Renderer* ren)
{
    char* Txt = new char[s.size() + 3];
	copy(s.begin(), s.end(), Txt);
	Txt[s.size()] = '\0';

    SDL_Color color = {r, g , b, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, Txt, color);
    if(textSurface == NULL)
    {
        cout << TTF_GetError() << endl;
    }
    CreateTexture(textSurface, ren);
    SDL_FreeSurface(textSurface);
    delete Txt;
    Txt = 0;
}

void Text::CreateTexture(SDL_Surface* sur,SDL_Renderer* ren)
{
	fontTexture = SDL_CreateTextureFromSurface(ren, sur);
}

void Text::Render(SDL_Renderer* ren, int x, int y)
{
	TextRect.x = x, TextRect.y = y;
	SDL_QueryTexture(fontTexture, NULL, NULL, &TextRect.w, &TextRect.h);
	SDL_RenderCopy(ren, fontTexture, NULL, &TextRect);
}

void Text::CloseFont()
{
	TTF_CloseFont(font);
}
