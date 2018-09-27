#include <stdio.h>

int pan[20][20];
int horizon;
int loc;
int c, r;

void checkFilled(int y, int x, int row)
{
    int i, j;
    int filled =0;
    int count = 0;

    for (i = 0; i < 4; i++)
    {
        pan[y - i][x] = 1;
    }
    for (i = 0; i < 4; i++)
    {
        filled = 1;
        for (j = 0; j < c; j++)
        {
            if(pan[y-i][j]==0){
                filled = 0;
                break;
            }
        }
        if(filled ==1) count++;
    }

    for (i = 0; i < 4; i++)
    {
        pan[y - i][x] = 0;
    }

    if(count > horizon){
        horizon = count;
        loc = x+1;
    }
}

int main(void)
{
    int n;

    int i, j, k, count;

    horizon = 0;
    loc = 0;

    scanf("%d %d", &c, &r);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &pan[i][j]);
        }
    }

    int flag = 0;

    for (i = r - 1; i > 2; i--)
    {
        for (j = 0; j < c; j++)
        {
            if (pan[i][j] == 0)
            {
                flag = 1;
                for (k = 0; k < 4; k++)
                {
                    if (pan[i - k][j] == 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    checkFilled(i, j, r);
                }
            }
        }
    }

    printf("%d %d", loc, horizon);
}