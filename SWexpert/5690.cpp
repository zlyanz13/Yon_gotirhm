#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
 
int T;
 
long long n, m, mdigit;
string number;
 
int main(void)
{
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        cin >> n >> m >> number;
 
        long long toCom = 0;
        int count = 0;
 
        for (int i = 0; i < n; i++)
        {
            toCom *= 10;
            toCom += number[i] - '0';
            // 0 을 어떻게 보느냐가 중요
            if (toCom % m == 0)
            {
                count++;
                toCom = 0;
            }
            else if (i == n - 1 && toCom % m != 0)
            {
                count = 0;
                break;
            }
            toCom = toCom % m;
        }
 
        long long answer = 1;
        if (count == 0)
        {
            answer = 0;
        }
        else
        {
            for (int i = 0; i < count - 1; i++)
            {
                answer *= 2;
                answer %= 1000000007;
            }
        }
 
        cout << "#" << testcase << " " << answer << endl;
    }
 
    return 0;
}
/*
  1 2 4 6
  1 2 3 4
1 0 1 1 1
2   0 1 2   
3     0 1 
4       0 
  
*/