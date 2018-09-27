#include <iostream>

using namespace std;

int N;

int arr[101];

int main(void)
{
    cin >> N;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        arr[i] = arr[i - 1] % 1000007 + arr[i - 2] % 1000007;
        arr[i] %= 1000007;
    }

    cout << arr[N] << endl;
}