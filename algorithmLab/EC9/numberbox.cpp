#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int *tocheck;

vector<int> sorted;

bool bins(int s, int f, int l)
{
    int m = (l + f) / 2;
    int b = sorted[m];

    bool recul = false;
    if (f > l)
    {
        return false;
    }
    if (b == s)
    {
        return true;
    }

    else if (b < s)
    {
        recul = bins(s, m + 1, l);
    }
    else if (b > s)
    {
        recul = bins(s, f, m - 1);
    }
    return recul;
}

int main(void)
{
    cin >> N;
    int card;
    for (int i = 0; i < N; i++)
    {
        cin >> card;
        sorted.push_back(card);
    }

    cin >> M;
    tocheck = new int[M];
    for (int i = 0; i < M; i++)
    {
        cin >> tocheck[i];
    }

    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < M; i++)
    {
        int c = tocheck[i];

        if (bins(c, 0, N - 1))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}