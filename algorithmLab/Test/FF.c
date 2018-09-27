#include <stdio.h>

int main(void)
{
    int a, b, c;
    int middle, high, low;
    int i, j;
    scanf("%d", &a);

    middle = (a / 2);

    for (i = 0; i < a; i++)
    {
        if (i == middle)
        {
            for (j = 0; j < (a / 2); j++)
            {
                printf(" ");
            }
            for (j = 0; j < a; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (j = 0; j < a - i - 1; j++)
            {
                printf(" ");
            }
            printf("*");
            for (j = 0; j < 2 * i - 1; j++)
            {
                printf(" ");
            }
            if (i != 0)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}