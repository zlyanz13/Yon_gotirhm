#include <iostream>
#include <math.h>

using namespace std;

long long int N;

int main(void)
{
    cin >> N;

    long long int left = 1;
    long long int right = (int)sqrt(N);

    long long int Max = -1;
    long long int answer = -1;

    while (left <= right)
    {
        long long int m = (left + right) / 2;
        long long int e = m * m + m;

        if (e > N)
        {
            answer = m-1;
            right = m - 1;
        }
        else if (e < N)
        {
            answer = m;
            left = m + 1;
        }
        else if (e == N)
        {
            cout << m << endl;
            return 0;
        }
    }

    cout << answer;
}