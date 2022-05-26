#include"rendergame.h"
#include"sokoban.h"
#include"music.h"
void rendergame( SDL_Renderer * renderer , SDL_Event *event, Playerpos *playerpos, string mute)
{
    switch( event -> key.keysym.sym)
    {
    case SDLK_LEFT:
        {
            switch (smap[playerpos->x][playerpos->y-1])
            {
            case 'w':
                break;
            case 'd':
                {
                    if( mute != "unmute" ) Playsound();
                    smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                    smap[playerpos->x][playerpos->y] = 'g';
                    playerpos->y--;
                    Move.push_back(3);
                    break;
                }
            case 'b':
                switch (smap[playerpos->x][playerpos->y-2])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        char tmp = smap[playerpos->x][playerpos->y-2];
                        smap[playerpos->x][playerpos->y-2] = smap[playerpos->x][playerpos->y-1];
                        smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = tmp;
                        playerpos->y--;
                        Move.push_back(3);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y-2] = 's';
                        smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y--;
                        Move.push_back(3);
                        break;
                    }
                }
                break;
            case 's':
                switch (smap[playerpos->x][playerpos->y-2])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y-2] = 'b';
                        smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y--;
                        Move.push_back(3);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y-2] = 's';
                        smap[playerpos->x][playerpos->y-1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y--;
                        Move.push_back(3);
                        break;
                    }
                }
                break;
            case 'g':
                {
                    if( mute != "unmute" ) Playsound();
                    swap( smap[playerpos->x][playerpos->y],smap[playerpos->x][playerpos->y-1]);
                    playerpos->y--;
                    Move.push_back(3);
                    break;
                }
            }
            for ( int i = 0; i < row; i++)
                for ( int j = 0; j < column; j++)
                {
                    levelchecksuccess(renderer);
                    if( !checkwin) drawmap(smap[i][j],i,j,renderer);
                    if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                }
        break;
        }
    case SDLK_RIGHT:
        {
            switch (smap[playerpos->x][playerpos->y+1])
            {
            case 'w':
                break;
            case 'd':
                {
                    if( mute != "unmute" ) Playsound();
                    smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                    smap[playerpos->x][playerpos->y] = 'g';
                    playerpos->y++;
                    Move.push_back(4);
                    break;
                }
            case 'b':
                switch (smap[playerpos->x][playerpos->y+2])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        char tmp = smap[playerpos->x][playerpos->y+2];
                        smap[playerpos->x][playerpos->y+2] = smap[playerpos->x][playerpos->y+1];
                        smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = tmp;
                        playerpos->y++;
                        Move.push_back(4);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y+2] = 's';
                        smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y++;
                        Move.push_back(4);
                        break;
                    }
                }
                break;
            case 's':
                switch (smap[playerpos->x][playerpos->y+2])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y+2] = 'b';
                        smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y++;
                        Move.push_back(4);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x][playerpos->y+2] = 's';
                        smap[playerpos->x][playerpos->y+1] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->y++;
                        Move.push_back(4);
                        break;
                    }
                }
                break;
            case 'g':
                {
                    if( mute != "unmute" ) Playsound();
                    swap( smap[playerpos->x][playerpos->y],smap[playerpos->x][playerpos->y+1]);
                    playerpos->y++;
                    Move.push_back(4);
                    break;
                }
            }
            for ( int i = 0; i < row; i++)
                for ( int j = 0; j < column; j++)
                {
                    levelchecksuccess(renderer);
                    if( !checkwin) drawmap(smap[i][j],i,j,renderer);
                    if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                }
        break;
        }
    case SDLK_UP:
        {
            switch (smap[playerpos->x-1][playerpos->y])
            {
            case 'w':
                break;
            case 'd':
                {
                    if( mute != "unmute" ) Playsound();
                    smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                    smap[playerpos->x][playerpos->y] = 'g';
                    playerpos->x--;
                    Move.push_back(1);
                    break;
                }
            case 'b':
                switch (smap[playerpos->x-2][playerpos->y])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        char tmp = smap[playerpos->x-2][playerpos->y];
                        smap[playerpos->x-2][playerpos->y] = smap[playerpos->x-1][playerpos->y];
                        smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = tmp;
                        playerpos->x--;
                        Move.push_back(1);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x-2][playerpos->y] = 's';
                        smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x--;
                        Move.push_back(1);
                        break;
                    }
                }
                break;
            case 's':
                switch (smap[playerpos->x-2][playerpos->y])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x-2][playerpos->y] = 'b';
                        smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x--;
                        Move.push_back(1);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x-2][playerpos->y] = 's';
                        smap[playerpos->x-1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x--;
                        Move.push_back(1);
                        break;
                    }
                }
                break;
            case 'g':
                {
                    if( mute != "unmute" ) Playsound();
                    swap( smap[playerpos->x][playerpos->y],smap[playerpos->x-1][playerpos->y]);
                    playerpos->x--;
                    Move.push_back(1);
                    break;
                }
            }
            for ( int i = 0; i < row; i++)
                for ( int j = 0; j < column; j++)
                {
                    levelchecksuccess(renderer);
                    if( !checkwin) drawmap(smap[i][j],i,j,renderer);
                    if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                }
        break;
        }
    case SDLK_DOWN:
        {
            switch (smap[playerpos->x+1][playerpos->y])
            {
            case 'w':
                break;
            case 'd':
                {
                    if( mute != "unmute" ) Playsound();
                    smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                    smap[playerpos->x][playerpos->y] = 'g';
                    playerpos->x++;
                    Move.push_back(2);
                    break;
                }
            case 'b':
                switch (smap[playerpos->x+2][playerpos->y])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        char tmp = smap[playerpos->x+2][playerpos->y];
                        smap[playerpos->x+2][playerpos->y] = smap[playerpos->x+1][playerpos->y];
                        smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = tmp;
                        playerpos->x++;
                        Move.push_back(2);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x+2][playerpos->y] = 's';
                        smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x++;
                        Move.push_back(2);
                        break;
                    }
                }
                break;
            case 's':
                switch (smap[playerpos->x+2][playerpos->y])
                {
                case 'g':
                    {
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x+2][playerpos->y] = 'b';
                        smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x++;
                        Move.push_back(2);
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
                        if( mute != "unmute" ) Playsound();
                        smap[playerpos->x+2][playerpos->y] = 's';
                        smap[playerpos->x+1][playerpos->y] = smap[playerpos->x][playerpos->y];
                        smap[playerpos->x][playerpos->y] = 'g';
                        playerpos->x++;
                        Move.push_back(2);
                        break;
                    }
                }
                break;
            case 'g':
                {
                    if( mute != "unmute" ) Playsound();
                    swap( smap[playerpos->x][playerpos->y],smap[playerpos->x+1][playerpos->y]);
                    playerpos->x++;
                    Move.push_back(2);
                    break;
                }
            }
            for ( int i = 0; i < row; i++)
                for ( int j = 0; j < column; j++)
                {
                    levelchecksuccess(renderer);
                    if( !checkwin) drawmap(smap[i][j],i,j,renderer);
                    if( ( smap[i][j] != 'p' && smap[i][j] != 's' && smap[i][j] != 'b' ) && dotpos[i][j] == 1 ) smap[i][j] = 'd';
                }
        break;
        }
    }
}

