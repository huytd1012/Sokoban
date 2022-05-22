#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"renderwintexture.h"
#include"levelchecksuccess.h"
#include"drawmap.h"
#include"getmap.h"
#include"drawmenu.h"
#include"renderbackgame.h"
#include"sokoban.h"
void rendergame( SDL_Renderer * renderer , SDL_Event *event, Playerpos *playerpos );
