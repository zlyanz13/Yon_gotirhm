#include <iostream>

using namespace std;

int N;
long long *a;
long long *b;
long long NUM = -1;
int main(void)
{
    long long int printIndex;

    cin >> N;
    a = new long long[N];
    b = new long long[N];

    long long Max = -1;
    long long Min = 1000000000;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
        if (Min > a[i])
        {
            Min = a[i];
        }
        if (Max < b[i])
        {
            Max = b[i];
        }
    }
    cin >> printIndex;

    long long left = Min;
    long long right = Max;

    while (left <= right)
    {
        long long m = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < N; i++)
        {
            if (a[i] < m && b[i] >= m)
            {
                count += m - a[i];
            }
            else if (b[i] < m)
            {
                count += b[i] - a[i] + 1;
            }
        }
        if (count == printIndex)
        {
            cout << m << endl;
            return 0;
        }
        else if (count < printIndex)
        {
            if (m > NUM)
            {
                NUM = m;
            }
            left = m + 1;
        }
        else if (count > printIndex)
        {
            if (m - 1 < NUM)
            {
                NUM = m - 1;
            }
            right = m - 1;
        }
    }

    cout << NUM;
}