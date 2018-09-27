#include <stdio.h>

int main(void)
{
    int n;
    int a[5];
    int i, count;

    scanf("%d", &n);
    scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);


    count = 0;
    for (i = 0; i < 5; i++)
    {
        if(a[i]==n)
        {
            count++;
        }
    }

    printf("%d", count);
}