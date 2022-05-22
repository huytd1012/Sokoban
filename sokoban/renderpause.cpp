#include"renderwintexture.h"
#include"levelchecksuccess.h"
#include"drawmap.h"
#include"getmap.h"
#include"sokoban.h"
void renderpause(SDL_Renderer *renderer)
{
    SDL_Surface *surface = SDL_LoadBMP("paused.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = 23.2;
    desRect.y = 291.3;
    desRect.w = 453.6;
    desRect.h = 212.4;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
}
