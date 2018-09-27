#include <stdio.h>

int arr[1000];
char tochar[30];

int intTochar(int a, int n)
{
    int i = 0;
    int count = 0;

    while (1)
    {
        if (a / n == 0)
        {
            if (a % n < 10)
            {
                tochar[i++] = '0' + a % n;
            }
            else
            {
                tochar[i++] = 'A' + a % n - 10;
            }
            break;
        }
        else
        {
            if (a % n < 10)
            {
                tochar[i++] = '0' + a % n;
            }
            else
            {
                tochar[i++] = 'A' + a % n - 10;
            }
            a = a / n;
        }
    }
    return i;
}

int main(void)
{
    int n, t, m, p;

    scanf("%d %d %d %d", &n, &t, &m, &p);

    int i, j, k;
    int digit;

    int count = 0;
    int talk = 0;
    printf("\"");
    for (i = 0; i < t * m; i++)
    {
        digit = intTochar(i, n);
        for (j = 0; j < digit; j++)
        {
            count++;

            if(m==p) p = 0;

            if (count % m == p)
            {
                printf("%c", tochar[digit - 1 - j]);
                talk++;
                if (talk == t){
                    printf("\"");
                    return 0;
                }
            }
        }
    }
}