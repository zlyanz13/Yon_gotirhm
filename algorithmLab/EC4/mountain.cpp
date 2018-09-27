#include <iostream>

using namespace std;

void recul(int n)
{
    if (n == 1)
    {
        cout << "1";
        return;
    }
    recul(n - 1);
    cout << n;
    recul(n - 1);
}

int main(void)
{
    int N;
    cin >> N;

    recul(N);
}