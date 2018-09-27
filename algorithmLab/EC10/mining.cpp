#include <iostream>

using namespace std;
int N, M;
int arr[1000][1000];
int brr[1000][1000];
int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i][0];
        brr[i][0] = sum;
    }
    sum = 0;
    for (int j = 0; j < M; j++)
    {
        sum += arr[0][j];
        brr[0][j] = sum;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            brr[i][j] = arr[i][j] + ((brr[i - 1][j] > brr[i][j - 1]) ? brr[i - 1][j] : brr[i][j - 1]);
        }
    }
    cout << brr[N - 1][M - 1] << endl;
}