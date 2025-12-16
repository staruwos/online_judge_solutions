#include <stdio.h>
#include <string.h>


int main()
{
    int w, h, i;
    char input[100];

    /*
     *	N = 0
     *	E = 1
     *	S = 2
     *	W = 3
     */
    char directions[] = {'N', 'E', 'S', 'W' };
    /* Read grid dimensions */
    fgets(input, 100, stdin);
    sscanf(input, "%d %d", &w, &h);

    int world[w][h];
    if(w > 50 || h > 50)
        return;

    while(fgets(input, 100, stdin) != NULL)
    {

        int lost = 0;
        /* first line is robot position and direction */
        int pos_x, pos_y, dir;
        char dir_c;

        sscanf(input, "%d %d %c", &pos_x, &pos_y, &dir_c);
        switch(dir_c)
        {
            case 'N':
                dir = 0;
                break;
            case 'E':
                dir = 1;
                break;
            case 'S':
                dir = 2;
                break;
            case 'W':
                dir = 3;
                break;
        }
        /* second line is instructions */
        fgets(input, 100, stdin);
        for(i = 0; i < strlen(input); i++)
        {
            if(input[i] == 'R')
            {
                dir++;
                dir = (dir >= 4) ? 0 : dir;
            }
            else if(input[i] == 'L')
            {
                dir--;
                dir = (dir < 0) ? 3 : dir;
            }
            else if(input[i] == 'F')
            {
                switch(dir)
                {
                    case 0:
                        pos_y++;
                        break;
                    case 1:
                        pos_x++;
                        break;
                    case 2:
                        pos_y--;
                        break;
                    case 3:
                        pos_x--;
                        break;
                }
            }

            if(pos_x > w)
            {
                if(world[pos_x-1][pos_y] == 1)
                    pos_x--;
                else
                {
                    pos_x--;
                    printf("%d %d %c LOST\n", pos_x, pos_y, directions[dir]);
                    world[pos_x][pos_y] = 1;
                    lost = 1;
                    break;
                }
            }
            else if(pos_x < 0)
            {
                if(world[pos_x+1][pos_y] == 1)
                    pos_x++;
                else
                {
                    pos_x++;
                    printf("%d %d %c LOST\n", pos_x, pos_y, directions[dir]);
                    world[pos_x][pos_y] = 1;
                    lost = 1;
                    break;
                }
            }
            else if(pos_y > h)
            {
                if(world[pos_x][pos_y-1] == 1)
                    pos_y--;
                else
                {
                    pos_y--;
                    printf("%d %d %c LOST\n", pos_x, pos_y, directions[dir]);
                    world[pos_x][pos_y] = 1;
                    lost = 1;
                    break;
                }
            }
            else if(pos_y < 0)
            {
                if(world[pos_x][pos_y+1] == 1)
                    pos_y++;
                else
                {
                    pos_y++;
                    printf("%d %d %c LOST\n", pos_x, pos_y, directions[dir]);
                    world[pos_x][pos_y] = 1;
                    lost = 1;
                    break;
                }
            }
            /*else
             *				printf("%d %d %c\n", pos_x, pos_y, directions[dir]);*/
        }
        if(lost != 1)
            printf("%d %d %c\n", pos_x, pos_y, directions[dir]);
    }

    return 0;
}
