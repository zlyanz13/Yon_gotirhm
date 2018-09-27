#include <stdio.h>
int arr[101][101];

int main(void)
{
    int i, j, k;
    int num;

    for (i = 0; i < 101; i++)
    {
        for (j = 0; j < 101; j++)
        {
            arr[i][j] = -1;
        }
    }

    scanf("%d", &num);

    int x, y, width, height;

    for (k = 0; k < num; k++)
    {
        scanf("%d %d %d %d", &x, &y, &width, &height);

        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                arr[y + i][x + j] = k;
            }
        }
    }

    int count;
    for (k = 0; k < num; k++)
    {
        count =0;
        for (i = 0; i < 101; i++)
        {
            for (j = 0; j < 101; j++)
            {
                if (arr[i][j] == k)
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
}