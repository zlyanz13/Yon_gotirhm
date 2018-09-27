#include <iostream>

using namespace std;

int main(void)
{
    int a1, a2;
    int b1, b2;
    int c1, c2;

    cin >> a1 >> a2 >> b1 >> b2;

    int max;
    int min;
    if (a2 > b2)
    {
        max = a2;
        min = b2;
    }
    else
    {
        max = b2;
        min = a2;
    }

    int i = 1;
    while (1)
    {
        c2 = max * i;
        if (c2 % min == 0)
        {
            break;
        }
        i++;
    }

    a1 = a1 * (c2 / a2);
    b1 = b1 * (c2 / b2);
    c1 = a1 + b1;

    if(c1>c2){
        max = c1;
        min = c2;
    }
    else{
        max = c2;
        min = c1;
    }

    for(i=min;i>1;i--){
        if(c2%i==0 && c1%i==0){
            c2 /= i;
            c1 /= i;
            break;
        }
    }
    

    cout << c1 << " " << c2;
}