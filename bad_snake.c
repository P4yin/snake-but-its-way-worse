#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    _Bool item = 0; 
    char map [9][9] =  
    {
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','X','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
    };
    for (int yy = 0; yy < 9; yy++)
    {
        for (int xx = 0; xx < 9; xx++)
        {
            printf("%c", map[yy][xx]);
        }
        printf("\n");
    }
    printf("Welcome to bad snake. Use the arrow keys to move. \nPress Enter at anytime to quit.\nDo not touch the A.\n");
    int score = 0;
    int rx,ry,sx,sy;
    int spikex [81] = {};
    int spikey [81] = {};
    int spikenum = 0;
    int y = 4, x = 4;
    int in = 0;
    int quit = 0;
    int state = 0;
    while (state == 0)
    {
        while (1) 
        {
            quit = getch();
            if (quit == 13)
            {
                state = 1; 
                break;
            }
            in = getch();
            if (in == 75)
            {
                map [y][x] = '-';
                if (x ==0)
                {
                    x = 8;
                }
                else
                {
                    x-=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (in == 72)
            {
                map [y][x] = '-';
                if (y ==0)
                {
                    y = 8;
                }
                else
                {
                    y-=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (in == 77)
            {
                map [y][x] = '-';
                if (x ==8)
                {
                    x = 0;
                }
                else
                {
                    x+=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (in == 80)
            {
                map [y][x] = '-';
                if (y ==8)
                {
                    y= 0;
                }
                else
                {
                    y+=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (quit == 13)
            {
                state = 1;
                break;
            }
        }
        if (y == ry && x == rx) 
        {
            item = 0;
            score+=50;
        }
        for (int i = 0; i < spikenum; i++)
        {
            if (y == spikey[i] && x == spikex[i])
            {
                state = 1;
                printf("You lost with a score of %d", score); 
                break;
            }
        }
        if (state == 1)
        {
            break;
        }
        if (item == 0)
        {
            if (spikenum < 80)
            {
                rx = rand()%9;
                ry = rand()%9;
                while (map[ry][rx] == 'X' || map[ry][rx] == 'A') 
                {
                    rx = rand()%9;
                    ry = rand()%9;
                }
                map[ry][rx] = '0';
                item = 1;
            }
        }
        else if (item == 1)
        {
            if (score > 0)
            {
                score-=1;
            }
        }
        int chance = rand()%10;
        if (chance == 0)
        {
            sx = rand()%9;
            sy = rand()%9;
            while (map[sy][sx] == 'X' || map[sy][sx] == '0' || map[sy][sx] == 'A')
            {
                sx = rand()%9;
                sy = rand()%9;
            }
            map[sy][sx] = 'A';
            spikex [spikenum] = sx;
            spikey [spikenum] = sy;
            spikenum+=1;
        }
        in = 0;
        printf("\n\n\n\n\n\n\n\n\n\nScore: %d\n", score); 
        for (int yy = 0; yy < 9; yy++)
        {
            for (int xx = 0; xx < 9; xx++)
            {
                printf("%c", map[yy][xx]);
            }
            printf("\n");
        }
    }
    printf("\nPress any key to exit...\n");
    getch();
    return 0;
}