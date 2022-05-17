#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"drawmap.h"
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
using namespace std;
void initSDL( SDL_Window*& window , SDL_Renderer*& renderer )
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        cout << "SDL failed to initialize\nSLD Error:\n" << SDL_GetError();
    }
    window = SDL_CreateWindow("Sokoban",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    if(!window) {
        cout << "Failed to open window\nSDL Error:\n" << SDL_GetError();
        return;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        cout << "Failed to create renderer\nSDL Error:\n" << SDL_GetError();
        return;
    }
}

void quitSDL( SDL_Window*& window , SDL_Renderer*& renderer )
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
	SDL_Event e;
	bool keyPressed = false;
	while (!keyPressed) {
		if (SDL_WaitEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				keyPressed = true;
			} else if (e.type == SDL_QUIT) {
				keyPressed = true;
			}
		}
		SDL_Delay(10000);
	}
}

SDL_Rect newSDL_Rect(int xs, int ys, int widths, int heights)
{
    SDL_Rect rectangular;
    rectangular.x = xs;
    rectangular.y = ys;
    rectangular.w = widths;
    rectangular.h = heights;
    return rectangular;
}

int smap[6][6]{
    {1,1,1,1,1,1},
    {1,0,0,0,4,1},
    {1,3,1,1,1,1},
    {1,0,1,0,0,0},
    {1,2,1,0,0,0},
    {1,1,1,0,0,0}
};


int main(int arc, char* argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    initSDL(window,renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

    for ( int i = 0; i < 6; i++)
        for ( int j = 0; j < 6; j++)
        {
            drawmap(smap[i][j],i,j,renderer);
        }

    SDL_RenderClear(renderer);
    SDL_Rect header = newSDL_Rect(0,0,1080,75);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer,&header);
    SDL_RenderClear(renderer);

    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    quitSDL(window,renderer);
    return 0;
}
