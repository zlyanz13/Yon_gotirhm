#include <iostream>
#include <string>
#include <vector>
using namespace std;

string palin;
int N, M;

long long alpha[27][2];
long long arr[1001][1001];

int main(void)
{
    cin >> N >> M >> palin;
    char tmpA;

    for (int i = 0; i < M; i++)
    {
        cin >> tmpA;
        cin >> alpha[tmpA - 'a'][0];
        cin >> alpha[tmpA - 'a'][1];
    }

    string backw = "";
    for (int i = N - 1; i > -1; i--)
    {
        backw.insert(backw.end(), palin[i]);
    }

    long long sum = 0;
    long long Min = 10000000;

    // string 의 Minimum Cost
    for (int i = 0; i < N; i++)
    {
        sum += (alpha[palin[i] - 'a'][0] < alpha[palin[i] - 'a'][1])
                   ? alpha[palin[i] - 'a'][0]
                   : alpha[palin[i] - 'a'][1];
    }

    arr[0][0] = sum;
    if (palin[0] == backw[0])
    {
        arr[0][0] -= (alpha[palin[0] - 'a'][0] < alpha[palin[0] - 'a'][1])
                         ? alpha[palin[0] - 'a'][0]
                         : alpha[palin[0] - 'a'][1];
    }

    // 초기열 최소화
    for (int i = 1; i < N; i++)
    {
        arr[i][0] = sum;
        arr[0][i] = sum;
        if (palin[i] == backw[0])
        {
            arr[i][0] -= ((alpha[palin[i] - 'a'][0] < alpha[palin[i] - 'a'][1])
                              ? alpha[palin[i] - 'a'][0]
                              : alpha[palin[i] - 'a'][1]);
        }
        else
        {
            arr[i][0] = arr[i - 1][0];
        }
        if (palin[0] == backw[i])
        {
            arr[0][i] -= ((alpha[backw[i] - 'a'][0] < alpha[backw[i] - 'a'][1])
                              ? alpha[backw[i] - 'a'][0]
                              : alpha[backw[i] - 'a'][1]);
        }
        else
        {
            arr[0][i] = arr[0][i-1];
        }
        Min = (arr[i][0] < Min) ? arr[i][0] : Min;
        Min = (arr[0][i] < Min) ? arr[0][i] : Min;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            arr[i][j] = arr[i - 1][j - 1];

            if (palin[i] == backw[j])
            {
                arr[i][j] -= (alpha[palin[i] - 'a'][0] < alpha[palin[i] - 'a'][1]
                                  ? alpha[palin[i] - 'a'][0]
                                  : alpha[palin[i] - 'a'][1]);

                Min = (arr[i][j] < Min) ? arr[i][j] : Min;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] < arr[i][j] ? arr[i - 1][j] : arr[i][j];
                arr[i][j] = arr[i][j - 1] < arr[i][j] ? arr[i][j - 1] : arr[i][j];
            }
        }
    }
    cout << Min << endl;
    /*
    cout << "\n";
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    */
}
/*
palindrome의 원래 최소비용을 구해서
뺀놈과 남은놈 중 최소를 구한다.
    abcbb
    bbcba
  b   c   b   a
a 0   0   0   1 
b 1   0   1   0
c 0   2   0   1
b 1   0   3   0

   abcb
      bcba
abc\b\cba 1100
ab|c|ba  1000
bcb|a|bcb 900

bb
bb
 acbbac 
      abab
    baba


a 삭제 : 1100
a 추가 : 1000
a 앞 bcb 삽입 : 900

최소비용 팰린드롬
 

문제
팰린드롬이란, 앞으로 읽으나 뒤로 읽으나 똑같은 문자열을 말한다. 예를 들어, “abcba”, “abccba” 등이 있을 수 있다. 문자열이 주어질 때, 이를 팰린드롬으로 만들기 위하여 우리는 두 가지 연산을 할 수 있다. 첫 째로는, 하나의 문자를 삽입하는 것이며, 둘 째로는 기존에 문자열 내에 존재하는 하나의 문자를 삭제하는 것이다. 이 두가지 연산을 통하여 주어진 문자열을 팰린드롬으로 만들 수 있다. 하나의 문자를 삽입 또는 삭제하기 위해서는 비용이 들어가며, 이는 각 알파벳마다 다르다. 문자열이 주어지고, 각 알파벳을 삽입할 때의 비용, 삭제할 때의 비용이 주어질 때, 주어진 문자열을 팰린드롬으로 만들기 위한 최소 비용을 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 문자열의 길이 N, 문자열 내에 존재하는 문자의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000) 두 번째 줄에는 문자열이 주어진다. 세 번째 줄부터 각 문자를 삽입, 삭제하는데 드는 비용이 주어진다. 이는 “a b c” 형식으로 주어지며, 그 뜻은 알파벳 a를 삽입하는데는 b, 삭제하는데는 c 만큼의 비용이 든다는 것을 의미한다. (문자열은 알파벳 소문자로만 구성되어있다.)  

출력
주어진 문자열을 팰린드롬으로 만들기 위한 최소 비용을 출력한다.

 

예제 입력
4 3
abcb
a 1000 1100
b 350 700
c 200 800
예제 출력
900
*/
