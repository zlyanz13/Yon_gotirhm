#include <iostream>
using namespace std;

int N;
int *arr;
int Max = -1;

void checkmax(int f, int l)
{
    int size = l - f + 1;
    int Min = 1000000;
    int minIndex;

    if (f > l)
    {
        return;
    }

    for (int i = f; i < l + 1; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
            minIndex = i;
        }
    }

    if (Max < Min * size)
    {
        Max = Min * size;
    }

    if (minIndex > 0)
    {
        checkmax(f, minIndex - 1);
    }
    if (minIndex < N - 1)
    {
        checkmax(minIndex + 1, l);
    }
}

int main(void)
{
    cin >> N;
    arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    checkmax(0, N - 1);

    cout << Max << endl;
}