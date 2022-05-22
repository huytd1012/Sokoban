#include"drawmap.h"
#include"getmap.h"
#include"levelchecksuccess.h"
#include"renderwintexture.h"
#include"renderbackgame.h"
#include"sokoban.h"
void renderbackgame(Playerpos *playerpos){
    getmap(playerpos);

    for( int i = 0; i < Move.size(); ++i ){
        switch( Move[i] )
        {
        case 3:
            {
                switch (smap[playerpos->x][playerpos->y-1])
                {
                case 'd':
                    {
                        smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y--;
                        break;
                    }
                case 'b':
                    switch (smap[playerpos->x][playerpos->y-2])
                    {
                    case 'g':
                        {
                            char tmp = smap[playerpos->x][playerpos->y-2];
                            smap[playerpos->x][playerpos->y-2] = smap[playerpos->x][playerpos->y-1];
                            smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = tmp;
                            playerpos->y--;
                        }
                        break;
                    case 'd':
                        {
                            smap[playerpos->x][playerpos->y-2] = 's';
                            smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y--;
                            break;
                        }
                    }
                    break;
                case 's':
                    switch (smap[playerpos->x][playerpos->y-2])
                    {
                    case 'g':
                        {
                            smap[playerpos->x][playerpos->y-2] = 'b';
                            smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y--;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x][playerpos->y-2] = 's';
                            smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y--;
                            break;
                        }
                    }
                    break;
                case 'g':
                    {
                        swap( smap[playerpos->x][playerpos->y],smap[playerpos->x][playerpos->y-1]);
                        playerpos->y--;
                        break;
                    }
                }
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                        if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
            break;
            }
        case 4:
            {
                switch (smap[playerpos->x][playerpos->y+1])
                {
                case 'd':
                    {
                        smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y++;
                        break;
                    }
                case 'b':
                    switch (smap[playerpos->x][playerpos->y+2])
                    {
                    case 'g':
                        {
                            char tmp = smap[playerpos->x][playerpos->y+2];
                            smap[playerpos->x][playerpos->y+2] = smap[playerpos->x][playerpos->y+1];
                            smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = tmp;
                            playerpos->y++;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x][playerpos->y+2] = 's';
                            smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y++;
                            break;
                        }
                    }
                    break;
                case 's':
                    switch (smap[playerpos->x][playerpos->y+2])
                    {
                    case 'g':
                        {
                            smap[playerpos->x][playerpos->y+2] = 'b';
                            smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y++;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x][playerpos->y+2] = 's';
                            smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->y++;
                            break;
                        }
                    }
                    break;
                case 'g':
                    {
                        swap( smap[playerpos->x][playerpos->y],smap[playerpos->x][playerpos->y+1]);
                        playerpos->y++;
                        break;
                    }
                }
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                        if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
            break;
            }
        case 1:
            {
                switch (smap[playerpos->x-1][playerpos->y])
                {
                case 'd':
                    {
                        smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x--;
                        break;
                    }
                case 'b':
                    switch (smap[playerpos->x-2][playerpos->y])
                    {
                    case 'g':
                        {
                            char tmp = smap[playerpos->x-2][playerpos->y];
                            smap[playerpos->x-2][playerpos->y] = smap[playerpos->x-1][playerpos->y];
                            smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = tmp;
                            playerpos->x--;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x-2][playerpos->y] = 's';
                            smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x--;
                            break;
                        }
                    }
                    break;
                case 's':
                    switch (smap[playerpos->x-2][playerpos->y])
                    {
                    case 'g':
                        {
                            smap[playerpos->x-2][playerpos->y] = 'b';
                            smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x--;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x-2][playerpos->y] = 's';
                            smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x--;
                            break;
                        }
                    }
                    break;
                case 'g':
                    {
                        swap( smap[playerpos->x][playerpos->y],smap[playerpos->x-1][playerpos->y]);
                        playerpos->x--;
                        break;
                    }
                }
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                        if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
            break;
            }
        case 2:
            {
                switch (smap[playerpos->x+1][playerpos->y])
                {
                case 'd':
                    {
                        smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x++;
                        break;
                    }
                case 'b':
                    switch (smap[playerpos->x+2][playerpos->y])
                    {
                    case 'g':
                        {
                            char tmp = smap[playerpos->x+2][playerpos->y];
                            smap[playerpos->x+2][playerpos->y] = smap[playerpos->x+1][playerpos->y];
                            smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = tmp;
                            playerpos->x++;
                            break;
                        }
                    case 'd':
                        {
                            smap[playerpos->x+2][playerpos->y] = 's';
                            smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x++;
                            break;
                        }
                    }
                    break;
                case 's':
                    switch (smap[playerpos->x+2][playerpos->y])
                    {
                    case 'g':
                        {
                            smap[playerpos->x+2][playerpos->y] = 'b';
                            smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x++;
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
                            smap[playerpos->x+2][playerpos->y] = 's';
                            smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                            smap[playerpos->x][playerpos->y] = 'g';
                            playerpos->x++;
                            break;
                        }
                    }
                    break;
                case 'g':
                    {
                        swap( smap[playerpos->x][playerpos->y],smap[playerpos->x+1][playerpos->y]);
                        playerpos->x++;
                        break;
                    }
                }
                for ( int i = 0; i < row; i++)
                    for ( int j = 0; j < column; j++)
                        if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
            break;
            }
        }
    }
}
