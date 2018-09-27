#include <iostream>

using namespace std;

#define ozs 1000007

int N;

int arr[100000];

int spl(int n)
{
    if (arr[n - 1] != -1)
    {
        return arr[n - 1];
    }

    int a = spl(n - 1);
    int b = spl(n - 2);
    int c = spl(n - 3);

    int sum = (a + b + c) % 1000007;

    if (arr[n - 1] == -1)
    {
        arr[n - 1] = sum;

        
    }
    return sum;
}

int main(void)
{
    cin >> N;

    fill_n(arr, 100000, -1);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;

    cout << spl(N);
}
