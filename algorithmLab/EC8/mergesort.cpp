#include <iostream>

using namespace std;

int N;
int *arr;
int *brr;

void merge(int f, int m, int l)
{
    int i = f;
    int j = m;

    int bindex = f;
    while (i < m && j < l)
    {
        if (arr[i] > arr[j])
        {
            brr[bindex++] = arr[j++];
        }
        else
        {
            brr[bindex++] = arr[i++];
        }
    }
    while (i < m)
    {
        brr[bindex++] = arr[i++];
    }
    while (j < l)
    {
        brr[bindex++] = arr[j++];
    }
    for (int a = f; a < l; a++)
    {
        arr[a] = brr[a];
    }
}

void mergeSort(int f, int l)
{
    if (f == l)
    {
        brr[f] = arr[f];
        return;
    }

    if (f < l)
    {

        int m = (f + l) / 2;
        int a, b;
        mergeSort(f, m);
        mergeSort(m + 1, l);

        merge(f, m + 1, l + 1);
    }
}

int main(void)
{
    cin >> N;

    arr = new int[N];
    brr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    mergeSort(0, N - 1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}