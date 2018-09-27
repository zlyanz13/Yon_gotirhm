#include <stdio.h>

int main(void)
{
    int a, b, c;
    int middle, high, low;
    int i;
    scanf("%d %d %d", &a, &c, &b);

    for (i = 0; i < (c - a + 1); i++)
    {
        printf("%d ", i + a);
    }

    for (i = 0; i < (c - b); i++)
    {
        printf("%d ", c - i - 1);
    }
}