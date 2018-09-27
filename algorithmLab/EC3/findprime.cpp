#include <iostream>

using namespace std;

int checkPrime(int i)
{
    if(i==1){
        return 0;
    }

    for (int a = i - 1; a > 1; a--)
    {
        if (i % a == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int N;

    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        int checked;
        checked = checkPrime(n);
        if (checked)
            count++;
    }
    cout << count;
}