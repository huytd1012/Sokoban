#include"drawmenu.h"
#include"sokoban.h"
void drawcontinue( SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture *texture )
{
    surface = SDL_LoadBMP("picture/continue.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = 0;
    desRect.y = 0;
    desRect.w = 500;
    desRect.h = 720;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}
