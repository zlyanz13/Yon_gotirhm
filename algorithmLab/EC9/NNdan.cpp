#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long **dan;

int main(void)
{
    cin >> N >> M;

    dan = new long long *[N];

    long long int left = 1;
    long long int right = N * N - 1;

    long long result = 0;

    while (left <= right)
    {
        long long int m = (left + right) / 2;
        long long int count = 0;

        for (long long int i = 0; i < N; i++)
        {
            if (i > m)
            {
                break;
            }

            if ((i + 1) * (N) <= m)
            {
                count += N;
            }
            else
            {
                count += m / (i + 1);
            }
        }

        if (count < M)
        {
            left = m + 1;
        }
        else if (count >= M)
        {
            result = m;
            right = m - 1;
        }
    }

    cout << result<< endl;
}