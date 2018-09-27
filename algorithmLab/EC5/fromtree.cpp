#include <iostream>

using namespace std;

int N;
int x, y;

int **link;
int *map;

void getD(int x, int y)
{
    int num1 = x;
    int num2 = y;
    map[x]++;
    map[y]++;

    int flag = -1;
    while (num1 != 0)
    {
        if (flag != -1)
        {
            break;
        }

        for (int i = 0; i < N - 1; i++)
        {
            if (link[i][1] == num1)
            {
                num1 = link[i][0];
                map[link[i][0]]++;
                if (map[link[i][0]] > 1)
                {
                    flag = link[i][0];
                }
                break;
            }
        }
    }

    while (num2 != 0)
    {
        if (flag != -1)
        {
            break;
        }
        for (int i = 0; i < N - 1; i++)
        {
            if (link[i][1] == num2)
            {
                num2 = link[i][0];
                map[link[i][0]]++;
                if (map[link[i][0]] > 1)
                {
                    flag = link[i][0];
                }
                break;
            }
        }
    }

    int d1 = 0;
    num1 = x;
    while (num1 != flag)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (link[i][1] == num1)
            {
                num1 = link[i][0];
                d1++;
                break;
            }
        }
    }

    int d2 = 0;
    num2 = y;
    while (num2 != flag)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (link[i][1] == num2)
            {
                num2 = link[i][0];
                d2++;
                break;
            }
        }
    }

    cout << d1 + d2;
}

int main(void)
{
    cin >> N >> x >> y;

    link = new int *[N - 1];
    map = new int[N];
    for (int k = 0; k < N; k++)
    {
        map[k] = 0;
        link[k] = new int[2];
    }

    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> link[i][0] >> link[i][1];
    }

    getD(x, y);
}