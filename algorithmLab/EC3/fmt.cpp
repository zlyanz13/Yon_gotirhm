#include <iostream>
using namespace std;

int minCount;
int distance;

void recul(int d, int v, int count)
{

    if (d < 0 || (d == 0 && v != 1))
    {
        return;
    }

    if (d == 0 && v == 1)
    {
        if (minCount > count)
        {
            minCount = count;
            return;
        }
    }

    if (count + 2 > minCount)
    {
        return;
    }

    recul(d - v - 1, v + 1, count + 1);

    if (count + 2 > minCount)
    {
        return;
    }

    if (count + 2 > minCount)
    {
        return;
    }

    if (v > 1)
    {
        recul(d - v + 1, v - 1, count + 1);
    }

    if (v != 0)
    {
        recul(d - (v), v, count + 1);
    }
}

int main(void)
{
    int x, y, d;
    cin >> x >> y;
    d = y - x;

    minCount = d;
    int i =0;
    for (i = 0; i < d/2+3; i++)
    {
        minCount = minCount - (i/2) -1;
        if (minCount <= 0)
        {
            minCount = i + 1;
            break;
        }
    }
    //recul(d - 1, 1, 1);

    cout << minCount;
}

/*
1 : 1
2 : 2
3 : 3 4
4 : 5 6
5 : 7 8 9
6 : 10 11 12
7 : 13 14 15 16 
8 : 17 18 19 20
9 : 21 22 23 24 25
10 : 26 27 28 29 30

*/