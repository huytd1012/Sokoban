#include"drawmute.h"
void drawmute( SDL_Renderer* renderer , string mute,int i,int j)
{
    string file = mute + ".bmp";
    SDL_Surface *surface = SDL_LoadBMP(file.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = i;
    desRect.y = j;
    desRect.w = 75;
    desRect.h = 75;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
}
