#include <iostream>

using namespace std;

int main(void)
{
    long long int a, b;
    long long int n, m;

    cin >> a >> b;

    if (a > b)
    {
        n = a;
        m = b;
    }
    else
    {
        n = b;
        m = a;
    }

    long long int i = 1;
    long long int k;

    while (1)
    {
        k = (n * i);
        k = k % m;
        if (k == 0)
        {
            break;
        }
        i++;
    }

    cout << n*i;
}