#include <stdio.h>

int main(void)
{
    int a, b, c;
    int arr[26][26];
    int minNumber, minIndex;
    int i, j;

    int tmp;

    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            arr[i][j] = -1;
        }
    }
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            arr[i][j] = 0;
        }
    }

    

    int x = 0;
    int y = 0;
    int number = 1;
    int direction = 1;
    while (1)
    {
        if(number == a*a+1) break;
        if (direction == 1)
        {
            arr[x][y++] =number++;
            if(arr[x][y]!=0){
                direction = 2;
                y--;
                x++;
            }
        }
        else if(direction == 2){
            arr[x++][y] = number++;
            if (arr[x][y] != 0)
            {
                direction = 3;
                x--;
                y--;
            }
        }
        else if (direction == 3)
        {
            arr[x][y--] = number++;
            if(y<0){
                direction = 4;
                y++;
                x--;
            }
            else if (arr[x][y] != 0)
            {
                direction = 4;
                y++;
                x--;
            }
        }
        else if (direction == 4)
        {
            arr[x--][y] = number++;
            if (arr[x][y] != 0)
            {
                direction = 1;
                x++;
                y++;
            }
        }
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}