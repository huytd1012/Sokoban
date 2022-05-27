#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include"drawcontinue.h"
#include"drawmenu.h"
#include"drawmap.h"
#include"drawmute.h"
#include"levelchecksuccess.h"
#include"getmap.h"
#include"music.h"
#include"sokoban.h"
#include"renderbackgame.h"
#include"rendergame.h"
#include"renderpause.h"
#include"renderwintexture.h"
#include"click.h"
using namespace std;
void initSDL( SDL_Window*& window , SDL_Renderer*& renderer )
{
    if(SDL_Init(SDL_INIT_EVERYTHING ) < 0 )
    {
        cout << "SDL failed to initialize\nSLD Error:\n" << SDL_GetError();
    }
    window = SDL_CreateWindow("Sokoban",500,75,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    if(!window) {
        cout << "Failed to open window\nSDL Error:\n" << SDL_GetError();
        return;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        cout << "Failed to create renderer\nSDL Error:\n" << SDL_GetError();
        return;
    }
    if (Mix_OpenAudioDevice(22050, MIX_DEFAULT_FORMAT, 2, 2048,"Speakers (Realtek(R) Audio)",0) == -1)
    {
        printf("%s", Mix_GetError());
        std::cout << '\n';
        return;
    }
}

void quitSDL( SDL_Window*& window , SDL_Renderer*& renderer )
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
char smap[10][10],lv = '1';
int row, column,screen = 1;
int dotpos[10][10];
bool checkwin = false;
string level;
vector <int> Move;
Playerpos playerpos;
vector<int> Newmove;
string mute = "mute";

int main(int arc, char* argv[])
{
    level = string(1,lv);
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    initSDL(window,renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderClear(renderer);
    drawmenu(renderer,surface,texture);
    //drawmute(renderer,mute,425,0);
    screen = 1;
    checkwin = false;
    getmap(&playerpos);
    int x,y;
    SDL_Event event;
	bool quit = false;
	while (!quit) {
		SDL_WaitEvent(&event);
		if( screen == 1 && event.type == SDL_MOUSEBUTTONDOWN )//màn hình menu
        {
            SDL_GetGlobalMouseState(&x,&y);
            if( x >= 565 && x <= 930 && y <= 401 && y >= 333 ){//bắt đầu chơi
                SDL_RenderClear(renderer);
                drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                getmap(&playerpos);
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                    {
                        drawmap(smap[i][j],i,j,renderer,surface,texture);
                    }
                checkwin = false;
                x = -1; y = -1;
                screen = 2;
                if( mute != "unmute" ) click();
            }
            if( x >= 565 && x <= 930 && y <= 490 && y >= 422 ){//thoát game
                if( mute != "unmute" ) click();
                quit = true;
                break;
            }
        }
        if( event.type ==  SDL_QUIT)
            {
                quit = true;
                break;
            }

        if( screen == 2 ) {//màn hình chơi
            if( event.type ==  SDL_KEYDOWN)//thao tác bấm bàn phím
                rendergame(renderer,&event,&playerpos,mute,surface,texture);

            if( event.type == SDL_MOUSEBUTTONDOWN){//thao tác bấm chuột
                SDL_GetGlobalMouseState(&x,&y);
                if( x >= 775 && x <= 850 && y <= 150 && y >= 75 ){//tắt âm
                    if( mute != "mute" ) click();
                    if( mute == "mute" ) mute = "unmute";
                    else mute = "mute";
                    drawmute(renderer,mute,275,0,surface,texture);
                }
                if( x >= 925 && y <= 150 && x <= 1000 && y >= 75 && checkwin == false){//chơi lại khi chưa xong level
                    if( mute != "unmute" ) click();
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    getmap(&playerpos);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    x = -1; y = -1;
                    Move = Newmove;
                }

                if( x >= 892 && x <= 974 && y >= 538 && y <= 620 && checkwin == true )//sang ván kế tiếp
                {
                    if( mute != "unmute" ) click();
                    lv++;
                    level = string(1,lv);
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    getmap(&playerpos);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    checkwin = false;
                    x = -1; y = -1;
                    Move = Newmove;
                }

                if( x >= 714 && x <= 795 && y >= 538 && y <= 620 && checkwin == true ){//chơi lại khi đã xong level
                    if( mute != "unmute" ) click();
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    getmap(&playerpos);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    checkwin = false;
                    x = -1; y = -1;
                    Move = Newmove;
                }

                if( lv != '1' && x >= 523 && x <= 606 && y >= 538 && y <= 620 && checkwin == true ){//quay lại ván trước
                    if( mute != "unmute" ) click();
                    lv--;
                    level = string(1,lv);
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    getmap(&playerpos);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    checkwin = false;
                    x = -1; y = -1;
                    Move = Newmove;
                }

                if( Move.size() != 0 && checkwin == false && x <= 925 && x >= 850 && y <= 150 && y >= 75 ) {//quay lại bước đi trước
                    if( mute != "unmute" ) click();
                    Move.pop_back();
                    renderbackgame(&playerpos);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    Playsound();
                    x = -1; y = -1;
                }
                if( x <= 575 && x >= 500 && y <= 150 && y >= 75 ){//tạm dừng
                    if( mute != "unmute" ) click();
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    renderpause(renderer,surface,texture);
                    screen = 4;
                    x = -1; y = -1;
                }
            }
        }

        if( screen == 4 ){
            if( event.type == SDL_MOUSEBUTTONDOWN){//thao tác bấm chuột
                SDL_GetGlobalMouseState(&x,&y);
                if( x <= 715 && x >= 633 && y <= 545 && y >= 466 ){//chơi tiếp
                    if( mute != "unmute" ) click();
                    SDL_RenderClear(renderer);
                    drawcontinue(renderer,surface,texture);
                    x = -1; y = -1;
                    screen = 1;
                }

                if( x <= 864 && x >= 784 && y <= 545 && y >= 466 ){//chuyển sang màn hình continue
                    if( mute != "unmute" ) click();
                    SDL_RenderClear(renderer);
                    drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                    for ( int i = 0; i < row; i++)
                        for ( int j = 0; j < column; j++)
                        {
                            drawmap(smap[i][j],i,j,renderer,surface,texture);
                        }
                    screen = 2;
                    x = -1; y = -1;
                }
            }
        }
        if( screen == 5 && event.type == SDL_MOUSEBUTTONDOWN )//màn hình continue
        {
            SDL_GetGlobalMouseState(&x,&y);
            if( x >= 565 && x <= 930 && y <= 401 && y >= 333 ){
                if( mute != "unmute" ) click();
                SDL_RenderClear(renderer);
                drawheader(renderer,surface,texture);drawmute(renderer,mute,275,0,surface,texture);
                getmap(&playerpos);
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                    {
                        drawmap(smap[i][j],i,j,renderer,surface,texture);
                    }
                checkwin = false;
                x = -1; y = -1;
                screen = 2;
            }
            if( x >= 565 && x <= 930 && y <= 490 && y >= 422 ){//thoát game
                if( mute != "unmute" ) click();
                quit = true;
                break;
            }
        }
	}
    SDL_UpdateWindowSurface(window);
    quitSDL(window,renderer);
    return 0;
}
