#include <stdio.h>
#include <string.h>

int main()
{
    int w, h, i;
    /* Increased buffer size slightly to be safe.
     *      Instructions are < 100 chars, plus newline and null terminator.
     */
    char input[120];

    /*
     *   Direction Mapping:
     *   N = 0
     *   E = 1
     *   S = 2
     *   W = 3
     */
    char directions[] = {'N', 'E', 'S', 'W' };

    /* CRITICAL FIX:
     *      1. Dimensions set to 51 to accommodate coordinates 0 to 50.
     *      2. Initialized to {0} so the "scents" are empty at the start.
     *      Your original code had garbage values here.
     */
    int world[51][51] = {0};

    /* Read grid dimensions */
    if(fgets(input, sizeof(input), stdin) == NULL) return 0;
    sscanf(input, "%d %d", &w, &h);

    while(fgets(input, sizeof(input), stdin) != NULL)
    {
        /* Handle empty lines if any appear between inputs */
        if(strlen(input) < 2) continue;

        int lost = 0;
        int pos_x, pos_y, dir;
        char dir_c;

        /* first line is robot position and direction */
        sscanf(input, "%d %d %c", &pos_x, &pos_y, &dir_c);

        switch(dir_c)
        {
            case 'N': dir = 0; break;
            case 'E': dir = 1; break;
            case 'S': dir = 2; break;
            case 'W': dir = 3; break;
        }

        /* second line is instructions */
        if(fgets(input, sizeof(input), stdin) == NULL) break;

        for(i = 0; i < strlen(input); i++)
        {
            /* If robot is already lost, stop processing instructions */
            if(lost) break;

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
                int prev_x = pos_x;
                int prev_y = pos_y;

                switch(dir)
                {
                    case 0: pos_y++; break; // N
                    case 1: pos_x++; break; // E
                    case 2: pos_y--; break; // S
                    case 3: pos_x--; break; // W
                }

                if(pos_x > w || pos_x < 0 || pos_y > h || pos_y < 0)
                {
                    if(world[prev_x][prev_y] == 1)
                    {
                        pos_x = prev_x;
                        pos_y = prev_y;
                    }
                    else
                    {
                        world[prev_x][prev_y] = 1;
                        printf("%d %d %c LOST\n", prev_x, prev_y, directions[dir]);
                        lost = 1;
                    }
                }
            }
        }

        if(!lost)
            printf("%d %d %c\n", pos_x, pos_y, directions[dir]);
    }

    return 0;
}
