#include <iostream>
#include <string>

using namespace std;

int arr[1000001];
int N;

int main(void)
{
    cin >> N;
    fill_n(arr, 1000001, -1);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    int a, b, c;
    for (int i = 4; i <= N; i++)
    {
        a = arr[i - 1];
        b = arr[i - 2];
        c = arr[i - 3];

        if (a && b && c)
        {
            arr[i] = 0;
        }

        else
        {
            arr[i] = 1;
        }
    }
    string answer = arr[N] ? "YES" : "NO";
    cout << answer << endl;
}