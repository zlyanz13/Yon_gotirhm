#include <stdio.h>

int allCount = 504;
int allCase[504];

void removeCase(int a, int b, int c, int strike, int ball)
{
    int i = 0;
    int tstrike;
    int tball;
    int tt;
    int tA;
    int tB;
    int tC;

    int count;

    int j;

    for (i = 0; i < 504; i++)
    {
        tt = allCase[i];
        if (tt == -1)
        {
            continue;
        }

        tC = tt % 10;
        tt /= 10;
        tB = tt % 10;
        tA = tt / 10;

        tball = 0;
        tstrike = 0;
        if(tA == a) tstrike++;
        if(tB == b) tstrike++;
        if(tC == c) tstrike++;

        if(tB==a || tC==a) tball++;
        if(tA ==b||tC==b) tball++;
        if(tA==c||tB==c) tball++;

        if(ball==tball && tstrike==strike) continue;
        else{
            allCase[i]=-1;
            allCount--;
        }
    }
}
/*
switch (strike)
{
case 0:
    if (ball == 3)
    {
        if ((tA == b && tB == c && tC == a) || (tA == c && tB == a && tC == b))
            break;
        else
        {
            allCase[i] = -1;
            allCount--;
            break;
        }
    }
    else if (ball == 2)
    {
        count = 0;
        if (tA != a && (tB == a || tC == a) && tB != b && (tA == b || tC == b) && (tA != c && tB != c && tC != c))
            break;
        else if (tB != b && (tA == b || tC == b) && tC != c && (tB == c || tA == c) && (tA != a && tB != a && tC != a))
            break;
        else if (tC != c && (tB == c || tA == c) && tA != a && (tB == a || tC == a) && (tA != b && tB != b && tC != b))
            break;
        else
        {
            allCase[i] = -1;
            allCount--;
            break;
        }
    }
    else if (ball == 1)
    {
        count = 0;
        if (tA != a && (tB == a || tC == a) && (tA != b && tB != b && tC != b) && (tA != c && tB != c && tC != c))
            break;
        else if (tB != b && (tA == b || tC == b) && (tA != a && tB != a && tC != a) && (tA != c && tB != c && tC != c))
            break;
        else if (tC != c && (tB == c || tA == c) && (tA != b && tB != b && tC != b) && (tA != a && tB != a && tC != a))
            break;
        else
        {
            allCase[i] = -1;
            allCount--;
        }
    }
    else if (ball == 0)
    {
        if ((tA == a || tB == a || tC == a) ||
            (tA == b || tB == b || tC == b) ||
            (tA == c || tB == c || tC == c))
        {
            allCase[i] = -1;
            allCount--;
            break;
        }
    }
    break;

case 1:
    if (ball == 0)
    {
        if (tA == a)
        {
            if (tB == c || tB == b || tC == b || tC == c)
            {
                allCase[i] = -1;
                allCount--;
            }
            break;
        }
        else if (tB == b)
        {
            if (tA == c || tA == a || tC == a || tC == c)
            {
                allCase[i] = -1;
                allCount--;
                break;
            }
        }
        else if (tC == c)
        {
            if (tB == b || tB == a || tA == b || tA == a)
            {
                allCase[i] = -1;
                allCount--;
                break;
            }
        }
        else
        {
            allCase[i] = -1;
            allCount--;
            break;
        }
        break;
    }
    else if (ball == 1)
    {
        if ((tA == a && tB == c && tC != b) ||
            (tA == a && tB != c && tC == b) ||
            (tA != c && tB == b && tC == a) ||
            (tA == c && tB == b && tC != a) ||
            (tA == b && tB != a && tC == c) ||
            (tA != b && tB == a && tC == c))
        {
            break;
        }
        else
        {
            allCase[i] = -1;
            allCount--;
        }
    }

    else if (ball == 2)
    {
        if ((tA == a && tB == c && tB == b))
            break;
        else if (tB == b && (tA == c && tC == a))
            break;
        else if ((tA == b && tB == a) && tC == c)
            break;
        else
        {
            allCase[i] = -1;
            allCount--;
            break;
        }
    }
    break;

case 2:
    if (tA == a && tB == b && tC != c)
        break;
    else if (tA == a && tB != b && tC == c)
        break;
    else if (tA != a && tB == b && tC == c)
        break;
    else
    {
        allCase[i] = -1;
        allCount--;
        break;
    }

    break;

case 3:
    allCount = 1;
    return;
    break;
}
*/

int main(void)
{
    int T;

    int three;
    int strike, ball;
    int a, b, c;

    int i, j, k, num;

    

    num = 0;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            if (i == j)
                continue;

            for (k = 1; k < 10; k++)
            {
                if (j != k && i != k)
                {
                    allCase[num++] = i * 100 + j * 10 + k;
                }
            }
        }
    }

    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d", &three, &strike, &ball);
        c = three % 10;
        three /= 10;
        b = three % 10;
        three /= 10;
        a = three;
        removeCase(a, b, c, strike, ball);

        if (allCount == 1)
            break;
    }
    /*
    allCount=0;
    for(i=0;i<504;i++){
        if(allCase[i]!=-1)allCount++;
    }
    */

    printf("%d", allCount);
}