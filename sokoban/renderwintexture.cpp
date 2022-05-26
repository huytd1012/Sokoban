#include"renderwintexture.h"
#include"levelchecksuccess.h"
#include"drawmap.h"
#include"getmap.h"
#include"sokoban.h"
void renderwintexture(SDL_Renderer *&renderer)
{
    string file = "winscr/winlevel" + level + ".bmp";
    SDL_Surface *surface = SDL_LoadBMP(file.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = 23.2;
    desRect.y = 249;
    desRect.w = 453.6;
    desRect.h = 297;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
}
