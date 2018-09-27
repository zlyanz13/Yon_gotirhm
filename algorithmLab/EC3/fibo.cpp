#include <iostream>

using namespace std;

int main(void)
{
    int n, n1, n2;
    int num;
    int sum = 0;

    int f0 = 0;
    int f1 = 1;

    cin >> num;

    if (num == 1)
    {
        n = 1;
    }
    else if (num == 0)
    {
        n = 0;
    }
    else
    {
        n2 = f0;
        n1 = f1;
        for (int i = 0; i < num - 1; i++)
        {
            n = n1 + n2;
            n2 = n1;
            n1 = n;
        }
    }

    cout << n;
}