#include <iostream>

using namespace std;

void tobin(int n)
{
    int i = 1;
    int count = 0;
    while (1)
    {
        if (n < i)
        {
            i /= 2;
            break;
        }
        count++;
        i *= 2;
    }

    while (1)
    {
        if(count ==0) break;
        if (n >= i)
        {
            n = n - i;
            i = i / 2;
            cout<<"1";
        }
        else{
            i=i/2;
            cout<<"0";
        }
        count --;
    }
}

int main(void)
{
    int N;
    cin >> N;

    tobin(N);
}