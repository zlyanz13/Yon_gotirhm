#include <iostream>

using namespace std;

int **link;
int *map;

void getA(int a, int b, int edge)
{
    int num1 = a;
    int num2 = b;

    map[a]++;
    map[b]++;

    while (num1 != 0)
    {
        for (int i = 0; i < edge; i++)
        {
            if (link[i][1] == num1)
            {
                map[link[i][0]]++;
                num1 = link[i][0];
                if (map[link[i][0]] > 1)
                {
                    cout << link[i][0];
                    return;
                }
                break;
            }
        }
    }

    while (num2 != 0)
    {
        for (int i = 0; i < edge; i++)
        {
            if (link[i][1] == num2)
            {
                map[link[i][0]]++;
                num2 = link[i][0];
                if (map[link[i][0]] > 1)
                {
                    cout << link[i][0];
                    return;
                }
                break;
            }
        }
    }
}

int main(void)
{
    int N;
    int x, y;
    cin >> N >> x >> y;

    link = new int *[N];
    map = new int[N];
    for (int k = 0; k < N; k++)
    {
        map[k] = 0;
        link[k] = new int[2];
    }

    int count = 0;
    int i = 0;

    while (count < 2)
    {
        cin >> link[i][0] >> link[i][1];

        if (link[i][1] == x || link[i][1] == y)
        {
            count++;
        }
        i++;
    }

    getA(x, y, i);
}