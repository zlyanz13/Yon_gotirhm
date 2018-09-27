#include <iostream>

using namespace std;

int checkPrime(int i)
{
    for (int a = 2; a < i; a++)
    {
        if (i % a == 0)
        {
            return 0;
        }
    }

    return 1;
}

int getNextPrime(int a)
{
    int b = a + 1;

    while (1)
    {
        if (checkPrime(b))
        {
            return b;
            break;
        }
        b++;
    }
}

int main(void)
{
    int N;
    cin >> N;

    int prime = 2;

    while (1)
    {
        while (N % prime == 0)
        {
            N = N/prime;
            cout << prime << endl;
        }

        if (N == 1)
        {
            break;
        }

// 이부분을 넣었더니 알고리즘 성공
        if(checkPrime(N)){
            prime = N;
            continue;
        }

        prime = getNextPrime(prime);
    }
}