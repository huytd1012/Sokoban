#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
const int SCREEN = 504;
const int SIZE = SCREEN / 6;
void drawmap( int t, int i, int j, SDL_Renderer* renderer );
