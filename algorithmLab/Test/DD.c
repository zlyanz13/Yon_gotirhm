#include <stdio.h>

int main(void)
{
    int a[3];
    int middle, high, low;
    int i;
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    low = a[0];
    high = a[0];
    int lownum = 0;
    int highnum = 0;
    for (i = 1; i < 3; i++)
    {
        if (low > a[i])
        {
            low = a[i];
            lownum = i;
        }
        if (high < a[i])
        {
            high = a[i];
            highnum = i;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (i!=lownum&&i!=highnum)
        {
            printf("%d", a[i]);
            return 0;
        }
    }
}