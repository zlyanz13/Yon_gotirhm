#include <iostream>

using namespace std;

int arr[100000] = {-1};

int getRCD(int r, int d)
{
    int min;
    if (r < d)
    {
        min = r;
    }
    else
    {
        min = d;
    }

    while (1)
    {
        if (r % min == 0 && d % min == 0)
        {
            break;
        }
        min--;
    }
    return min;
}

int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int rcd = arr[1] - arr[0];
    for (int i = 1; i < N - 1; i++)
    {
        rcd = getRCD(rcd, arr[i + 1] - arr[i]);
    }

    int empty = 0;
    int current = arr[0];
    for (int i = 1; i < N; i++)
    {
        while (1)
        {
            current = current + rcd;
            if (arr[i] <= current)
            {
                break;
            }
            empty++;
        }
    }
    cout << empty;
}