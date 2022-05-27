#include "drawmap.h"
#include "getmap.h"
#include"sokoban.h"
void drawheader(SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture *texture)
{
    string file = "picture/level" + level + ".bmp";
    surface = SDL_LoadBMP(file.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect desRect;
    desRect.x = 0;
    desRect.y = 0;
    desRect.w = 500;
    desRect.h = 75;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}
void drawmap( char a, int i, int j, SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture *texture)
{
    string s;
    surface = NULL;
    texture = NULL;
    SDL_Rect desRect;
    if( ( a != 'p' && a != 's' && a != 'b' ) && dotpos[i][j] == 1 ) s = "picture/d.bmp";
    else if( a != 'n' ) s = "picture/" + string(1,a) + ".bmp";
    //cout << a << ' ';
    const char* tmp = s.c_str();
    surface = SDL_LoadBMP(tmp);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    desRect.x = (SCREEN_WIDTH-50*column)/2 + j*50;
    desRect.y = 75+(645-50*row)/2 + i*50;
    desRect.w = 50;
    desRect.h = 50;
    SDL_RenderCopy(renderer, texture, 0, &desRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}
