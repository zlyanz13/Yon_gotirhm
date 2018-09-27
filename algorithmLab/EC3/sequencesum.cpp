#include <iostream>

using namespace std;

int arr[1000][1000] = {-1};

int main(void)
{
    int N;
    cin >> N;

    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int b[N];

    for (i = 1; i < N - 1; i++)
    {
        b[i] = (arr[i][i + 1] + arr[i - 1][i] - arr[i - 1][i + 1]) / 2;
    }

    b[0] = arr[0][1] - b[1];
    b[N - 1] = arr[N - 2][N - 1] - b[N - 2];

    for(i=0;i<N;i++){
        cout << b[i] << " ";
    }
}