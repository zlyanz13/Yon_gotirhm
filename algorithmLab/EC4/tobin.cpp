#include <iostream>

using namespace std;

char arr[31] = {0};

void tobin(int n, int k, int c)
{
    if (n == c && k == 0)
    {
        cout << arr<<endl;
        return;
    }
    else if ((n == c && k != 0))
    {
        return;
    }

    if (k > -1)
    {
        arr[c] = '1';
        tobin(n, k - 1, c + 1);
    }
    arr[c] = '0';
    tobin(n, k, c + 1);
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    arr[n] = '\0';

    tobin(n, k, 0);
}