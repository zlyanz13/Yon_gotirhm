#include <iostream>

using namespace std;

int N;
int arr[100001][3];
int brr[100001][3];

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    brr[0][0] = arr[0][0];
    brr[0][1] = arr[0][1];
    brr[0][2] = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        brr[i][0] = arr[i][0] + ((brr[i - 1][1] > brr[i - 1][2]) ? brr[i - 1][1] : brr[i - 1][2]);
        brr[i][1] = arr[i][1] + ((brr[i - 1][0] > brr[i - 1][2]) ? brr[i - 1][0] : brr[i - 1][2]);
        brr[i][2] = arr[i][2] + ((brr[i - 1][0] > brr[i - 1][1]) ? brr[i - 1][0] : brr[i - 1][1]);
    }

    int MAX;

    int r = brr[N - 1][0];
    int g = brr[N - 1][1];
    int b = brr[N - 1][2];

    if (r >= g && r >= b)
    {
        MAX = r;
    }
    else if (g >= r && g >= b)
    {
        MAX = g;
    }
    else if (b >= r && b >= g)
    {
        MAX = b;
    }

    cout << MAX << endl;
}