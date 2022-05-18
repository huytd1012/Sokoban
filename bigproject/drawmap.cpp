#include "drawmap.h"
void drawheader(SDL_Renderer* renderer)
{
    SDL_Surface *surface = SDL_LoadBMP("header.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = 0;
    desRect.y = 0;
    desRect.w = 500;
    desRect.h = 75;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
}
void drawmap( char a, int i, int j, SDL_Renderer* renderer)
{
    SDL_Surface* surface = NULL;SDL_Texture* texture = NULL;SDL_Rect desRect;
    string s = string(1,a) + ".bmp";
    //cout << a << ' ';
    const char* tmp = s.c_str();
    surface = SDL_LoadBMP(tmp);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    desRect.x = (SCREEN_WIDTH-SCREEN)/2 + j*SIZE;
    desRect.y = 75+(645-SCREEN)/2 + i*SIZE;
    desRect.w = SIZE;
    desRect.h = SIZE;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}
