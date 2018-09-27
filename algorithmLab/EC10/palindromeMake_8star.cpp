#include <iostream>
#include <string>

using namespace std;

string palin;
int arr[1001][1001];
int Max = 0;

int MaxV(int y, int x)
{
    int tmpM = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (arr[i][j] > tmpM)
            {
                tmpM = arr[i][j];
            }
        }
    }
    return tmpM;
}

int main(void)
{
    cin >> palin;
    int size = palin.size();

    string backw = "";
    for (int i = size - 1; i > -1; i--)
    {
        backw.insert(backw.end(), palin[i]);
    }

    arr[0][0] = palin[0] == backw[0] ? 1 : 0;

    for (int i = 1; i < size; i++)
    {
        arr[i][0] = (palin[i] == backw[0]) ? 1 : arr[i - 1][0];
    }
    for (int j = 1; j < size; j++)
    {
        arr[0][j] = (palin[0] == backw[j]) ? 1 : arr[0][j - 1];
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (palin[i] == backw[j])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
            }
        }
    }
    Max = arr[size - 1][size - 1];

    cout << size - Max << endl;
}
/*

  a d e c b e a
a 1           1  
e     2     2
b         3
c       3
e     2     4
d   2
a 1           5


  a b c c b d a c
a 1 1 1 1 1 1 1 1
b   2     2
c     3 3       3
c     3 4
b   2     5
d           6
a 1           7
c     1 1       8

팰린드롬 만들기
 

문제
팰린드롬이란, 앞으로 읽으나 뒤로 읽으나 똑같은 문자열을 말한다. 예를 들어, “abcba”, “abccba” 등이 있을 수 있다. 문자열이 주어질 때, 이를 팰린드롬으로 만들기 위하여 추가해야 하는 최소의 문자 개수를 출력하는 프로그램을 작성하시오. 예를 들어, 문자열이 “abca” 로 주어질 경우, ‘b’만 추가하면 “abcba” 를 만들 수 있으므로, 이 때는 1개의 문자만 추가하면 된다. 또 다른 예로써, 문자열이 “adcba” 로 주어질 경우에는, 문자 2개를 추가해야 한다.

 

입력
첫 번째 줄에 문자열이 주어진다. 이 문자열의 길이는 1,000 을 넘지 않는다.  

출력
주어진 문자열을 팰린드롬으로 만들기 위해서 추가해야 하는 문자 개수의 최솟값을 출력한다.

 

예제 입력
adcba
예제 출력
2
 

예제 입력
abccbdbac
예제 출력
3
*/
