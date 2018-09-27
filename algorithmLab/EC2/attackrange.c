#include <stdio.h>

int arr[100][100];

int main(void)
{

    int map;
    int i, j;

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            arr[i][j] = -1;
        }
    }

    scanf("%d", &map);
    for (i = 0; i < map; i++)
    {
        for (j = 0; j < map; j++)
        {
            arr[i][j] = 0;
        }
    }

    int x, y, range;
    scanf("%d %d %d", &x, &y, &range);
    x--;
    y--;

    int subX;
    int subY;
    int sub;

    for (i = 0; i < map; i++)
    {
        for (j = 0; j < map; j++)
        {
            subX = y - j;
            subY = x - i;
            if (subX < 0)
                subX = -subX;
            if (subY < 0)
                subY = -subY;
            sub = subX+subY;

            
            if (i == x & j == y)
            {
                printf("x ");
            }
            else if (sub <= range)
            {
                printf("%d ", sub);
            }
            else
            {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}