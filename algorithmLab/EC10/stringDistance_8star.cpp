#include <iostream>
#include <string>

using namespace std;

string Astring;
string Bstring;
int Asize;
int Bsize;
int count = 0;
int Max = -1;

int arr[201][201];
int brr[201][201];

int MaxV(int y, int x)
{
    int tmpM = -1;
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
    cin >> Astring >> Bstring;
    Asize = Astring.length();
    Bsize = Bstring.length();

    for (int i = 0; i < Asize; i++)
    {
        if (Astring[i] == Bstring[0])
            arr[i][0] = 1;
    }
    for (int j = 0; j < Bsize; j++)
    {
        if (Astring[0] == Bstring[j])
            arr[0][j] = 1;
    }

    for (int i = 1; i < Asize; i++)
    {
        for (int j = 1; j < Bsize; j++)
        {
            if (Astring[i] == Bstring[j])
            {
                arr[i][j] = MaxV(i, j) + 1;
            }
        }
    }

    Max = MaxV(Asize, Bsize);

    cout << Asize + Bsize - 2 * Max << endl;
}

/*
LCS Algorithm(Longest Common Subsequence Algorithm)
a b c d e f d
e f a b c d d
=> find longest Common string arr

  a b c d e f
e         0
f           0 
a 1 
b   2
c     3
d       4

abcabcd
abccabc
  a b c a b c d
a 1     1
b   2     2 
c     3     3
c     3     3
a 1     4
b   2     5
c     3     6
  b a b d e f
a   1 
b 1   2
d       3 
c
f           4
e         4

두 문자열 사이의 거리
 

문제
두 문자열 A, B 가 주어질 때, 두 문자열 사이의 거리를 구하려 한다. 여기서 거리는 다음과 같이 정의된다. 문자열 A가 주어질 때, 여기서 하나의 연산은 하나의 알파벳을 삽입 또는 삭제하는 것을 의미한다. 문자열 A와 B 사이의 거리란, A에서 시작하여 B를 만들기 위한 최소 연산의 횟수로 정의된다. 예를 들어, 문자열 A가 “abcabcd”이고, 문자열 B가 “abccabc” 라면, 문자열 A와 B 사이의 거리는 2가 된다. 왜냐하면 문자열 A의 세 번째에 ‘c’를 삽입하고, 가장 마지막에 있는 ‘d’를 삭제하면 문자열 B를 얻기 때문이다. 두 문자열이 주어질 때, 두 문자열 사이의 거리를 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄과 두 번째 줄에 문자열이 주어지며, 이 문자열의 길이는 200을 넘지 않는다.  

출력
두 문자열 사이의 거리를 출력한다.

 

예제 입력
abcabcd
abccabc
예제 출력
2
*/