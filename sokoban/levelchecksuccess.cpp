#include"levelchecksuccess.h"
#include"drawmap.h"
#include"getmap.h"
#include"renderwintexture.h"
#include"sokoban.h"
void levelchecksuccess(SDL_Renderer *&renderer)
{
    bool check = 1;
    for( int i = 0; i < row; ++i )
    for( int j = 0; j < column; ++j )
    {
        if( dotpos[i][j] && smap[i][j] != 's' ) check = 0;
    }
    if( check ) {
        renderwintexture(renderer);
        checkwin = true;
    }
}
