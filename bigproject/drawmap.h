#pragma once
#include<bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 720;
const int SCREEN = 360;
const int SIZE = SCREEN / 6;
void drawmap( char a, int i, int j, SDL_Renderer* renderer );
void drawheader(SDL_Renderer* renderer);
