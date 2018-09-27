#include <iostream>

using namespace std;

int N;
int arr[1000000];
int brr[1000000];
int MAX = -1;
int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    brr[0] = arr[0];

    for (int i = 1; i < N; i++)
    {
        brr[i] = (arr[i] + brr[i - 1] > arr[i]) ? (arr[i] + brr[i - 1]) : (arr[i]);
        if (brr[i] > MAX)
        {
            MAX = brr[i];
        }
    }

    cout << MAX << endl;
}