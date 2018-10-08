#include <iostream>
#include <math.h>

using namespace std;

int T;
int main(void)
{
    cin >> T;

    for (int testcase = 1; testcase <= T; testcase++)
    {
        unsigned long long N;

        cin >> N;

        unsigned long long left = 1;
        unsigned long long right = N / 8;
        unsigned long long m = 0;
        int flag = 0;

        if (N == 1000000000000000000)
        {
            cout << "#" << testcase << " "
                 << "1000000" << endl;
            continue;
        }
        else if (N >= 100000000000000)
        {
            right = 1000000;
        }
        else if (N >= 1000000000000)
        {
            right = 100000;
        }
        else if (N >= 1000000000)
        {
            right = 10000;
        }
        else
        {
            right = N / 4;
        }

        if (N == 1)
        {
            cout << "#" << testcase << " "
                 << "1" << endl;
            continue;
        }

        while (left <= right)
        {
            m = (left + right) / 2;
            unsigned long long k = m * m * m;
            //cout << "m : " << m << " / k : " << k << endl;
            if (k == N)
            {
                flag = 1;
                break;
            }

            if (k > N)
            {
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }

        if (!flag)
        {
            cout << "#" << testcase << " "
                 << "-1" << endl;
            continue;
        }

        cout << "#" << testcase << " " << m << endl;
    }

    return 0;
}