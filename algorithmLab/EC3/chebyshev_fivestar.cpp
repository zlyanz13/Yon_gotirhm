#include <iostream>

using namespace std;

int checkPrime(int i)
{
    int max = i;
    for (int a = 3; a < max; a = a + 2)
    {
        if (i % a == 0)
        {
            return 0;
        }
        //핵심라인
        max=i/a + 1;
        // 통상적으로 루트로 리밋 걸어라
        //
    }
    return 1;
}

int getNumPrime(int n)
{
    int i;
    int count = 0;
    int max = 2 * n + 1;

    if (n > 1)
    {
        if (n % 2 != 0)
            n = n + 1;
    }
    for (i = n + 1; i < max; i = i + 2)
    {
        if (checkPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    int N;
    int num;
    while (1)
    {
        cin >> N;
        if (N == 0)
        {
            return 0;
        }

        num = getNumPrime(N);
        cout << num << endl;
    }
}