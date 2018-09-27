#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int arr[100];
    int brr[100];
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * brr[i] - sum;
        sum = sum + arr[i];
        
        cout << arr[i]<< " ";
    }


}