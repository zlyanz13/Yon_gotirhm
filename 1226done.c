#include <stdio.h>

int solved = 0;

int maze[16][16];

int checkSquare(int a, int b, int c);
void solveMaze(int a, int b, int c);

#define NORTH 1
#define WEST 2
#define SOUTH 3
#define EAST 4

int main(void)
{
    int testCase;
    int testCount;
    int i, j, k;
    unsigned long int map;

    for (testCount = 0; testCount < 10; testCount++)
    {
        solved = 0;
        scanf("%d", &testCase);

        for (i = 0; i < 16; i++)
        {
            scanf("%lu", &map);

            for (j = 15; j > -1; j--)
            {
                maze[i][j] = (int)(map % 10);
                map = map / 10;
            }
        }
        //input done
        
        solveMaze(1, 1, NORTH);
        printf("#%d %d\n", testCase, solved);
    }
}

void solveMaze(int a, int b, int c)
{
    int check;
    while (1)
    {
        check = checkSquare(a, b, c);

        if (solved == 1)
        {
            return;
        }
       

        if (check == 5)
        {
            solved = 1;
            return;
        }
        else if(check == NORTH){
            maze[a][b]=1;
            a = a -1;
            c = SOUTH;
            continue;
        }
        else if (check == WEST)
        {
            maze[a][b]=1;
            b = b - 1;
            c = EAST;
            continue;
        }
        else if (check == SOUTH)
        {
            maze[a][b] = 1;
            a = a + 1;
            c= NORTH;
            continue;
        }
        else if (check == EAST)
        {
            maze[a][b] = 1;
            b = b + 1;
            c = WEST;
            continue;
        }
        else if(check == 0) return;
        else if(check == -1) break;
    }

    if (maze[a - 1][b] == 0 && c != NORTH)
    {
        solveMaze(a - 1, b, SOUTH);
    }

    if (maze[a][b - 1] == 0 && c != WEST)
    {
        solveMaze(a, b - 1, EAST);
    }

    if (solved == 1)
    {
        return;
    }

    if (maze[a + 1][b] == 0 && c != SOUTH)
    {
        solveMaze(a + 1, b, NORTH);
    }

    if (maze[a][b + 1] == 0 && c != EAST)
    {
        solveMaze(a, b + 1, WEST);
    }

    return;
}

int checkSquare(int a, int b, int c)
{
    int count = -1;
    int direction;
    if (maze[a - 1][b] == 3 || maze[a][b - 1] == 3 ||
        maze[a + 1][b] == 3 || maze[a][b + 1] == 3)
    {
        return 5;
    }

    if (maze[a - 1][b] == 0 && c != NORTH)
    {
        count ++;
        direction = NORTH;
    }

    if (maze[a][b - 1] == 0 && c != WEST)
    {
        count ++;
        direction = WEST;
    }

    if (maze[a + 1][b] == 0 && c != SOUTH)
    {
        count ++;
        direction = SOUTH;
    }

    if (maze[a][b + 1] == 0 && c != EAST)
    {
        count++;
        direction = EAST;
    }

    if(count == 0){
        return direction;
    }
    else if(count == -1){
        return 0;
    }

    return -1;
}