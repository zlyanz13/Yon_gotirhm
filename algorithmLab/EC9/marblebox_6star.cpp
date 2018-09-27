#include <iostream>

using namespace std;

int N, M;
int *arr;
int Z = 1000000000;

int main(void)
{
    cin >> N >> M;
    arr = new int[M];
    int sum = -1;

    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
        if (arr[i] > sum)
        {
            sum = arr[i];
        }
    }

    int left = 1;
    int right = sum;

    while (left <= right)
    {
        int m = (left + right) / 2;
        int count = 0;
        int flag = 0;

        for (int i = 0; i < M; i++)
        {
            int cc = arr[i] / m;

            count += cc;
            if (arr[i] % m != 0)
            {
                count++;
            }
        }

        if (count <= N)
        {
            right = m - 1;
            if (m < Z)
            {
                Z = m;
            }
        }
        else if (count > N)
        {
            left = m + 1;
        }
    }


    cout << Z << endl;
}
