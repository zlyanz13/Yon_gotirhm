#include <stdio.h>

int main(void)
{
    int a, b, c;

    int bToa, cTob;

    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        bToa = b - a;
        cTob = c - b;

        if(bToa == cTob){
            printf("AP %d\n", bToa+c);
            continue;
        }

        bToa = b/a;
        cTob = c/b;

        printf("GP %d\n", bToa*c);
    }
}