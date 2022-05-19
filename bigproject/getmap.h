#pragma once
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
extern char smap[10][10];
extern int row, column;
extern int dotpos[10][10];
struct Playerpos{
    int x,y;
};
extern Playerpos playerpos;
void getmap( string level);
