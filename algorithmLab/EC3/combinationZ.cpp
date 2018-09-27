#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;


    int sum = 1;
    int divi = 1;

    int count = 0;

    int ssTwo = 0;
    int ssFive = 0;
    int dTwo = 0;
    int dFive = 0;
    for (int i = 0; i < m; i++)
    {
        int Dsum = n - i;

        while (Dsum % 2 == 0)
        {
            Dsum = Dsum / 2;
            ssTwo++;
        }
        while (Dsum % 5 == 0)
        {
            Dsum = Dsum / 5;
            ssFive++;
        }

        int Ddivi = m - i;

        while (Ddivi % 2 == 0)
        {
            Ddivi = Ddivi / 2;
            dTwo++;
        }
        while (Ddivi % 5 == 0)
        {
            Ddivi = Ddivi / 5;
            dFive++;
        }
    }
    int s2 = ssTwo-dTwo;
    int s5 = ssFive - dFive;

    if (s2 > s5)
        s2 = s5;
    count = s2;

    cout << count;
}