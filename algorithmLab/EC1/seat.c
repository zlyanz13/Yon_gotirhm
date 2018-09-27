#include <stdio.h>

int main(void)
{
    int column, row;
    int square;
    int que;
    int i, direction;

    scanf("%d %d", &column, &row);
    square = column * row;

    scanf("%d", &que);

    if (square < que)
    {
        printf("0");
        return 0;
    }

    int x = 1;
    int y = 1;

    int overX = 2;
    int overY = 1;

    int Limit = 0;
    direction = 1;
    for (i = 0; i < que - 1; i++)
    {
        if (x == overX && y == overY)
        {
            if ((row - Limit) != (1 + Limit))
            {
                overX++;
                overY++;
                Limit++;
            }            
        }

        if (direction == 1)
        {
            if (y + 1 > row - Limit)
            {
                direction = 2;
                x++;
                continue;
            }
            y++;
        }
        else if (direction == 2)
        {
            if (x + 1 > column - Limit)
            {
                direction = 3;
                y--;
                continue;
            }
            x++;
        }
        else if (direction == 3)
        {
            if (y - 1 < 1 + Limit)
            {
                direction = 4;
                x--;
                continue;
            }
            y--;
        }
        else if (direction == 4)
        {
            if (x - 1 < 1 + Limit)
            {
                direction = 1;
                y++;
                continue;
            }
            x--;
        }
    }

    printf("%d %d", x, y);
}