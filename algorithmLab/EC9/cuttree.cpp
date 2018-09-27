#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long int M;
long long int *arr;
long long int height = -1;
int flag = 0;

void binaryS(int f, int l)
{
    long long int cut = (f + l) / 2;

    long long int tmpSum = 0;

    if (f > l || flag)
    {
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > cut)
        {
            tmpSum = tmpSum + arr[i] - cut;
        }
    }

    if (tmpSum == M)
    {
        height = cut;
        flag = 1;
        return;
    }
    else if (tmpSum > M)
    {
        if (height < cut || !flag)
        {
            height = cut;
        }
        binaryS(cut + 1, l);
    }
    else if (tmpSum < M)
    {
        binaryS(f, cut - 1);
    }
}

int main(void)
{
    cin >> N >> M;
    arr = new long long int[N];
    long long int Max = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }

    binaryS(0, Max);

    cout << height << endl;
}