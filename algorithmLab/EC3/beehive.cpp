#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int m;

    n = n - 1;
    if (n == 0)
    {
        cout << "1";
        return 0;
    }
    int i =1;
    while(1){
        n = n-6*i++;
        if(n<1){
            break;
        }
    }
    cout << i;
    
}