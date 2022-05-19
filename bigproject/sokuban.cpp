#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"drawmap.h"
#include"getmap.h"
//const int SCREEN_WIDTH = 500;
//const int SCREEN_HEIGHT = 720;
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

char smap[10][10];
int row, column;
int dotpos[10][10];
Playerpos playerpos;
string level = string("2");

int main(int arc, char* argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    initSDL(window,renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderClear(renderer);
    drawheader(renderer);

    getmap(level);
    for ( int i = 0; i < row; i++)
        for ( int j = 0; j < column; j++)
        {
            drawmap(smap[i][j],i,j,renderer);
        }

    SDL_Event event;
	bool quit = false;
	while (!quit) {
		SDL_WaitEvent(&event) != 0;
		switch(event.type)
		{
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym)
            {
            case SDL_QUIT:
                {
                    quit = true;
                    break;
                }
            case SDLK_LEFT:
                {
                    switch (smap[playerpos.x][playerpos.y-1])
                    {
                    case 'w':
                        break;
                    case 'd':
                        {
                            smap[playerpos.x][playerpos.y-1] = smap[playerpos.x][playerpos.y];
                            smap[playerpos.x][playerpos.y] = 'g';
                            playerpos.y--;
                            break;
                        }
                    case 'b':
                        switch (smap[playerpos.x][playerpos.y-2])
                        {
                        case 'g':
                            {
                                char tmp = smap[playerpos.x][playerpos.y-2];
                                smap[playerpos.x][playerpos.y-2] = smap[playerpos.x][playerpos.y-1];
                                smap[playerpos.x][playerpos.y-1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = tmp;
                                playerpos.y--;
                            }
                            break;
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x][playerpos.y-2] = 's';
                                smap[playerpos.x][playerpos.y-1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y--;
                                break;
                            }
                        }
                        break;
                    case 's':
                        switch (smap[playerpos.x][playerpos.y-2])
                        {
                        case 'g':
                            {
                                smap[playerpos.x][playerpos.y-2] = 'b';
                                smap[playerpos.x][playerpos.y-1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y--;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x][playerpos.y-2] = 's';
                                smap[playerpos.x][playerpos.y-1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y--;
                                break;
                            }
                        }
                        break;
                    case 'g':
                        {
                            swap( smap[playerpos.x][playerpos.y],smap[playerpos.x][playerpos.y-1]);
                            playerpos.y--;
                            break;
                        }
                    }
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer);
                            if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                        }
                break;
                }
            case SDLK_RIGHT:
                {
                    switch (smap[playerpos.x][playerpos.y+1])
                    {
                    case 'w':
                        break;
                    case 'd':
                        {
                            smap[playerpos.x][playerpos.y+1] = smap[playerpos.x][playerpos.y];
                            smap[playerpos.x][playerpos.y] = 'g';
                            playerpos.y++;
                            break;
                        }
                    case 'b':
                        switch (smap[playerpos.x][playerpos.y+2])
                        {
                        case 'g':
                            {
                                char tmp = smap[playerpos.x][playerpos.y+2];
                                smap[playerpos.x][playerpos.y+2] = smap[playerpos.x][playerpos.y+1];
                                smap[playerpos.x][playerpos.y+1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = tmp;
                                playerpos.y++;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x][playerpos.y+2] = 's';
                                smap[playerpos.x][playerpos.y+1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y++;
                                break;
                            }
                        }
                        break;
                    case 's':
                        switch (smap[playerpos.x][playerpos.y+2])
                        {
                        case 'g':
                            {
                                smap[playerpos.x][playerpos.y+2] = 'b';
                                smap[playerpos.x][playerpos.y+1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y++;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x][playerpos.y+2] = 's';
                                smap[playerpos.x][playerpos.y+1] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.y++;
                                break;
                            }
                        }
                        break;
                    case 'g':
                        {
                            swap( smap[playerpos.x][playerpos.y],smap[playerpos.x][playerpos.y+1]);
                            playerpos.y++;
                            break;
                        }
                    }
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer);
                            if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                        }
                break;
                }
            case SDLK_UP:
                {
                    switch (smap[playerpos.x-1][playerpos.y])
                    {
                    case 'w':
                        break;
                    case 'd':
                        {
                            smap[playerpos.x-1][playerpos.y] = smap[playerpos.x][playerpos.y];
                            smap[playerpos.x][playerpos.y] = 'g';
                            playerpos.x--;
                            break;
                        }
                    case 'b':
                        switch (smap[playerpos.x-2][playerpos.y])
                        {
                        case 'g':
                            {
                                char tmp = smap[playerpos.x-2][playerpos.y];
                                smap[playerpos.x-2][playerpos.y] = smap[playerpos.x-1][playerpos.y];
                                smap[playerpos.x-1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = tmp;
                                playerpos.x--;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x-2][playerpos.y] = 's';
                                smap[playerpos.x-1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x--;
                                break;
                            }
                        }
                        break;
                    case 's':
                        switch (smap[playerpos.x-2][playerpos.y])
                        {
                        case 'g':
                            {
                                smap[playerpos.x-2][playerpos.y] = 'b';
                                smap[playerpos.x-1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x--;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x-2][playerpos.y] = 's';
                                smap[playerpos.x-1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x--;
                                break;
                            }
                        }
                        break;
                    case 'g':
                        {
                            swap( smap[playerpos.x][playerpos.y],smap[playerpos.x-1][playerpos.y]);
                            playerpos.x--;
                            break;
                        }
                    }
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer);
                            if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                        }
                break;
                }
            case SDLK_DOWN:
                {
                    switch (smap[playerpos.x+1][playerpos.y])
                    {
                    case 'w':
                        break;
                    case 'd':
                        {
                            smap[playerpos.x+1][playerpos.y] = smap[playerpos.x][playerpos.y];
                            smap[playerpos.x][playerpos.y] = 'g';
                            playerpos.x++;
                            break;
                        }
                    case 'b':
                        switch (smap[playerpos.x+2][playerpos.y])
                        {
                        case 'g':
                            {
                                char tmp = smap[playerpos.x+2][playerpos.y];
                                smap[playerpos.x+2][playerpos.y] = smap[playerpos.x+1][playerpos.y];
                                smap[playerpos.x+1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = tmp;
                                playerpos.x++;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x+2][playerpos.y] = 's';
                                smap[playerpos.x+1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x++;
                                break;
                            }
                        }
                        break;
                    case 's':
                        switch (smap[playerpos.x+2][playerpos.y])
                        {
                        case 'g':
                            {
                                smap[playerpos.x+2][playerpos.y] = 'b';
                                smap[playerpos.x+1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x++;
                                break;
                            }
                        case 'w':
                            break;
                        case 'b':
                            break;
                        case 's':
                            break;
                        case 'd':
                            {
                                smap[playerpos.x+2][playerpos.y] = 's';
                                smap[playerpos.x+1][playerpos.y] = smap[playerpos.x][playerpos.y];
                                smap[playerpos.x][playerpos.y] = 'g';
                                playerpos.x++;
                                break;
                            }
                        }
                        break;
                    case 'g':
                        {
                            swap( smap[playerpos.x][playerpos.y],smap[playerpos.x+1][playerpos.y]);
                            playerpos.x++;
                            break;
                        }
                    }
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer);
                            if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                        }
                break;
                }
            break;
            }
		}
		//SDL_Delay(5000);
	}
    SDL_UpdateWindowSurface(window);
    quitSDL(window,renderer);
    return 0;
}
