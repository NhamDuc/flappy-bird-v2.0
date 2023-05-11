#pragma once
#include "Object.h"
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

class Text : public Object
{
public:
    void CreateFont(const char* path, int size);
    void TXT(string s, int r, int g, int b, SDL_Renderer* ren);
    void CreateTexture(SDL_Surface* sur, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren, int x, int y);
    void CloseFont();
private:
    TTF_Font* font;
    SDL_Rect TextRect;
	SDL_Texture* fontTexture;
};
