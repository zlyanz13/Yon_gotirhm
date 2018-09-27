#include <stdio.h>

int arr[9][9];

int main(void)
{
    int i, j;

    int max = -1;
    int x = -1;
    int y = -1;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }


    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if(arr[i][j]>max){
                max = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n%d %d", max, x+1, y+1);
}