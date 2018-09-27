#include <iostream>
#include <math.h>

using namespace std;

int N;
int arr[100001];

int main(void)
{
    cin >> N;

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4; // 4 1 1 1 / 1 1 1 4
    arr[8] = 2; // 4 4

    arr[9] = 1;
    arr[10] = 2;
    arr[11] = 3;
    arr[12] = 3; // 4 4 4 / 9 1 1 1
    arr[13] = 2; // 4 4 4 1 / 9 4
    arr[14] = 3; // 9 4 1 / 4 4 4 1 1
    arr[15] = 4; // 9 4 1 1 /

    arr[16] = 1; //  16
    arr[19] = 3; // 16 1 1 1 / 9 9

    arr[42] = 3;  // 36 4 1 1 / 25 16 1
    arr[47] = 4;  // 36 9 1 1 / 25 9 9 4
    arr[130] = 2; // 100 25 4 1 / 81 49
    arr[243] = 3; // 225 9 9 / 81 81 81 / 196 25 9 9 4
    arr[245] = 2; // 196 / 49
    for (int i = 6; i <= N; i++)
    {
        int s = (int)sqrt(i);
        int n = s * s;

        if (i == n)
        {
            arr[i] = 1;
            continue;
        }

        int Min = 100000;

        for (int j = s; j >= 1; j--)
        {
            int sq = j * j;
            int tmp = arr[sq] + arr[i - sq];
            if (tmp < Min)
            {
                Min = tmp;
            }
        }
        arr[i] = Min;
    }

    cout << arr[N];
}