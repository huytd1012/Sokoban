#include "drawmap.h"
void drawmap( int t, int i, int j, SDL_Renderer* renderer)
{
    SDL_Surface* surface = NULL;SDL_Texture* texture = NULL;SDL_Rect desRect;
    if(t == 1 ) {
        surface = SDL_LoadBMP("wall.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        desRect.x = 288 + i*SIZE;
        desRect.y = 108 + j*SIZE;
        desRect.w = SIZE;
        desRect.h = SIZE;
        SDL_RenderCopy(renderer, texture, 0, &desRect);
        SDL_RenderPresent(renderer);
    }
    else if(t == 2 ){
        surface = SDL_LoadBMP("player.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        desRect.x = 288 + i*SIZE;
        desRect.y = 108 + j*SIZE;
        desRect.w = SIZE;
        desRect.h = SIZE;
        SDL_RenderCopy(renderer, texture, 0, &desRect);
        SDL_RenderPresent(renderer);
    }
    else if( t == 3 ){
        surface = SDL_LoadBMP("box.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        desRect.x = 288 + i*SIZE;
        desRect.y = 108 + j*SIZE;
        desRect.w = SIZE;
        desRect.h = SIZE;
        SDL_RenderCopy(renderer, texture, 0, &desRect);
        SDL_RenderPresent(renderer);
    }
    else if( t == 4 ){
        surface = SDL_LoadBMP("dot.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        desRect.x = 288 + i*SIZE;
        desRect.y = 108 + j*SIZE;
        desRect.w = SIZE;
        desRect.h = SIZE;
        SDL_RenderCopy(renderer, texture, 0, &desRect);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(texture);
}
