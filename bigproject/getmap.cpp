#include"getmap.h"
void getmap( string level )
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
        if( tmp != 'n' ) smap[i][j] = tmp;
        if( tmp == 'p' ) playerpos = { i,j };
        if( tmp == 'd' || tmp == 's' ) dotpos[i][j] = 1;;
    }
}
