#include"getmap.h"
#include"sokoban.h"
#include"playerpos.h"
void getmap(Playerpos *playerpos)
{
    memset( dotpos , 0 , sizeof(dotpos) );
    string file = level + ".txt";
    ifstream in(file.c_str());
    in >> row >> column;
    for( int i = 0; i < row; ++i )
    for( int j = 0; j < column; ++j)
    {
        char tmp;
        in >> tmp;
        smap[i][j] = tmp;
        if( tmp == 'p' ) {
            playerpos->x = i;
            playerpos->y = j;
        }
        if( tmp == 'd' || tmp == 's' ) dotpos[i][j] = 1;;
    }
}
