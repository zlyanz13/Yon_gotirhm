#include <stdio.h>

int arr[10][10];

int main(void)
{
    int i, j, k;

    int n;

    scanf("%d", &n);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
            }
            else if (arr[i][j] == 1)
            {
                arr[i][j] = 0;
            }

            if (arr[j][i] == 0)
            {
                arr[j][i] = 1;
            }
            else if (arr[j][i] == 1)
            {
                arr[j][i] = 0;
            }
        }
        if (arr[i][i] == 0)
        {
            arr[i][i] = 1;
        }
        else if (arr[i][i] == 1)
        {
            arr[i][i] = 0;
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}