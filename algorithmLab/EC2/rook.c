#include <stdio.h>

int arr[8][8];

int main(void)
{
    int i, j;
    int pos = 0;

    int rookNum = 0;

    int rookX1, rookY1;
    int rookX2, rookY2;

    int kingX, kingY;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2)
            {
                if (rookNum == 0)
                {
                    rookX1 = j;
                    rookY1 = i;
                }
                else if (rookNum == 1)
                {
                    rookX2 = j;
                    rookY2 = i;
                }
                rookNum++;
            }
            if (arr[i][j] == 1)
            {
                kingX = j;
                kingY = i;
            }
        }
    }

    int flag = 0;

    if (kingX == rookX1)
    {
        if (kingY > rookY1)
        {
            flag = 1;
            for (i = 0; i < kingY - rookY1-1; i++)
            {
                if (arr[rookY1 + i + 1][kingX] != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                pos = 1;
        }
        else
        {
            flag = 1;
            for (i = 0; i < rookY1 - kingY-1; i++)
            {
                if (arr[kingY + i + 1][kingX] != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                pos = 1;
            }
        }
        if (pos)
        {
            printf("%d", pos);
            return 0;
        }
    }

    if (kingY == rookY1)
    {
        if (kingX > rookX1)
        {
            flag = 1;
            for (i = 0; i < kingX - rookX1-1; i++)
            {
                if (arr[kingY][rookX1 + i + 1] != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                pos = 1;
        }
        else
        {
            flag = 1;
            for (i = 0; i < rookX1 - kingX-1; i++)
            {
                if (arr[kingY][kingX + i + 1] != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                pos = 1;
        }
        if (pos)
        {
            printf("%d", pos);
            return 0;
        }
    }

    if (rookNum == 2)
    {

        if (kingX == rookX2)
        {
            if (kingY > rookY2)
            {
                flag = 1;
                for (i = 0; i < kingY - rookY2-1; i++)
                {
                    if (arr[rookY2 + i + 1][kingX] != 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    pos = 1;
            }
            else
            {
                flag = 1;
                for (i = 0; i < rookY2 - kingY-1; i++)
                {
                    if (arr[kingY + i + 1][kingX] != 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    pos = 1;
            }
        }

        if (kingY == rookY2)
        {
            if (kingX > rookX2)
            {
                flag = 1;
                for (i = 0; i < kingX - rookX2-1; i++)
                {
                    if (arr[kingY][rookX2 + i + 1] != 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    pos = 1;
            }
            else
            {
                flag = 1;
                for (i = 0; i < rookX2 - kingX-1; i++)
                {
                    if (arr[kingY][kingX + i + 1] != 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    pos = 1;
            }
        }
    }

    printf("%d", pos);
}