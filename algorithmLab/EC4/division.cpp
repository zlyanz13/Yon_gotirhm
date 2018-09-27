#include <iostream>

using namespace std;

int count;
int arr[20] = {0};

void getDiv(int n, int a, int max)
{
    if (n == 0)
    {
        for (int i = 0; i < a - 1; i++)
        {
            cout << arr[i] << "+";
        }
        cout << arr[a - 1] << endl;
        count++;
        return;
    }

    int limit;
    limit = max;
    if (n < max)
    {
        limit = n;
    }

    for (int i = limit; i > 0; i--)
    {
        arr[a] = i;
        getDiv(n - i, a + 1, i);
    }
}

int main(void)
{
    int n;
    cin >> n;

    count = 0;

    getDiv(n, 0, n - 1);
    cout << count;
}