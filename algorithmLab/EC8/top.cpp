#include <iostream>

using namespace std;

int N;
int *arr;
int *brr;

int main(void)
{
    cin >> N;
    arr = new int[N];
    brr = new int[N];

    brr[0] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = N - 1; i > 0; i--)
    {
        int Max = arr[i];
        int maxIndex = i;

        for (int j = i - 1; j > -1; j--)
        {
            if (arr[j] > Max)
            {
                maxIndex = j;
                break;
            }
        }

        if (maxIndex == i)
        {
            brr[i] = 0;
        }
        else
        {
            brr[i] = maxIndex + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;
}