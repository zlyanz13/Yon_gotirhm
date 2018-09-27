#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    long int ncm;

    long int sum = 1;
    long int divi = 1;

    for (int i = 0; i < m; i++)
    {
        sum = sum * (n - m + 1 + i);
        divi = divi * (i + 1);

        if (sum % divi == 0)
        {
            sum = sum / divi;
            divi = 1;
        }
    }
    ncm = sum / divi;

    cout << ncm;
}