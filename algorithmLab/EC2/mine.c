#include <stdio.h>

int arr[100][100];

int main(void)
{
    int row, column;
    int x, y;

    int i, j, k;

    scanf("%d %d", &row, &column);

    scanf("%d %d", &y, &x);
    x--;
    y--;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int count = 0;

    if (arr[y][x] == 1)
    {
        printf("game over");
        return 0;
    }

    if (x > 0 && y > 0)
    {
        if (arr[y - 1][x - 1] == 1)
            count++;
    }

    if (y > 0)
    {
        if (arr[y - 1][x] == 1)
            count++;
    }

    if (x + 1 < column && y > 0)
    {
        if (arr[y - 1][x + 1] == 1)
            count++;
    }

    if (x > 0)
    {
        if (arr[y][x - 1] == 1)
            count++;
    }

    if (x + 1 < column)
    {
        if (arr[y][x + 1] == 1)
            count++;
    }
    if (x > 0 && y + 1 < row)
    {
        if (arr[y + 1][x - 1] == 1)
            count++;
    }
    if(y+1<row){
        if(arr[y+1][x]==1) count++;
    }

    if(x+1<column&&y+1<row){
        if(arr[y+1][x+1]==1) count++;
    }

    printf("%d", count);
}