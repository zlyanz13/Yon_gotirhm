#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int *arr;
int *brr;

void binS(int k)
{
    int left = 0;
    int right = N - 1;
    int c = -1;

    while (left <= right)
    {
        int m = (left + right) / 2;

        if (arr[m] == k)
        {
            c = m;
            break;
        }

        if (arr[m] > k)
        {
            right = m - 1;
        }
        else if (arr[m] < k)
        {
            left = m + 1;
        }
    }
    if (c == -1)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int Max = c + 1;
        int Min = c - 1;
        while (Max < N)
        {
            if (arr[Max] == k)
            {
                Max++;
            }
            else
            {
                break;
            }
        }
        while (Min > -1)
        {
            if (arr[Min] == k)
            {
                Min--;
            }
            else
            {
                break;
            }
        }

        cout << Max - Min - 1 << endl;
    }
}

int main(void)
{
    cin >> N >> M;
    arr = new int[N];
    brr = new int[M];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < M; i++)
    {
        cin >> brr[i];
    }
    for (int i = 0; i < M; i++)
    {
        binS(brr[i]);
    }
}