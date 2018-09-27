#include <stdio.h>

int main(void)
{
    int n;
    int tile[100][100];
    int x, y;
    int i, j, count;

    scanf("%d %d", &x, &y);

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf("%d", &tile[i][j]);
        }
    }

    for (i = 0; i < x; i++)
    {
        for (j = y-1; j >-1; j--)
        {
            printf("%d ", tile[i][j]);
        }
        printf("\n");
    }
}