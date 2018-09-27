#include <stdio.h>
int a[5][5];

void checkArr(int x, int y)
{
    int num = a[x][y];
    int cross[4];

    int i;

    if (x - 1 < 0)
    {
        cross[0] = 10;
    }
    else
    {
        cross[0] = a[x - 1][y];
    }

    if (y - 1 < 0)
    {
        cross[1] = 10;
    }
    else
    {
        cross[1] = a[x][y - 1];
    }

    if (x + 1 > 4)
    {
        cross[2] = 10;
    }
    else
    {
        cross[2] = a[x + 1][y];
    }

    if (y + 1 > 4)
    {
        cross[3] = 10;
    }
    else
    {
        cross[3] = a[x][y + 1];
    }

    for (i = 0; i < 4; i++)
    {
        if (num >= cross[i]){
            printf("%d ", num);
            return;
        }
    }

    printf("* ");
}

int main(void)
{
    int n;

    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            checkArr(i, j);
        }
        printf("\n");
    }
}