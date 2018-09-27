#include <stdio.h>

int main(void)
{
    int a, b, c;
    char arr[100][100];
    int middle, high, low;
    int i, j;
    scanf("%d %d", &a, &b);

    for(i =0;i<b;i++){
        for(j=0;j<a;j++){
            arr[i][j]=' ';
        }
    }

    for (i = 0; i < 100; i++)
    {
        arr[0][i] = '*';
        arr[99][i] = '*';
        arr[i][0] = '*';
    }

    for (i = 0; i < a; i++)
    {
        arr[b-1][i] = '*';
    }
    for (i = 0; i < b; i++)
    {
        arr[i][a-1] = '*';
    }

    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}