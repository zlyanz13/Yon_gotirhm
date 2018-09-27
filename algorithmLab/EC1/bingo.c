#include <stdio.h>

int pan[5][5];

int checkNum(int num)
{
    int i, j;
    int bingoLine = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (pan[i][j] == num)
            {
                pan[i][j] = 0;
            }
        }
    }

    int isBingo = 1;
    for (i = 0; i < 5; i++)
    {
        if (pan[i][i] != 0)
        {
            isBingo = 0;
            break;
        }
    }

    if (isBingo)
        bingoLine++;

    isBingo = 1;
    for (i = 0; i < 5; i++)
    {
        if (pan[4 - i][i] != 0)
        {
            isBingo = 0;
            break;
        }
    }

    if (isBingo)
        bingoLine++;

    for (i = 0; i < 5; i++)
    {
        isBingo = 1;
        for (j = 0; j < 5; j++)
        {
            if (pan[i][j] != 0)
            {
                isBingo = 0;
                break;
            }
        }
        if(isBingo) bingoLine++;
    }

    for (i = 0; i < 5; i++)
    {
        isBingo = 1;
        for (j = 0; j < 5; j++)
        {
            if (pan[j][i] != 0)
            {
                isBingo = 0;
                break;
            }
        }
        if (isBingo)
            bingoLine++;
    }

    if(bingoLine >2){
        return 1;
    }
    return 0;
}

int main(void)
{
    int n;

    int i, j, k, count;
    int number;
    int bingo = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &pan[i][j]);
        }
    }

    for (i = 0; i < 25; i++)
    {
        scanf("%d", &number);
        bingo = checkNum(number);
        if (bingo == 1)
        {
            printf("%d", i + 1);
            return 0;
        }
    }
}