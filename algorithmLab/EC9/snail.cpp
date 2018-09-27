#include <iostream>

using namespace std;

int A, B, V;

int main(void)
{
    cin >> A >> B >> V;

    int sum = -1;
    int i = 1;
    while (sum < V)
    {
        sum = A * i - B * i + B;
        i++;
    }

    cout << i - 1;
}