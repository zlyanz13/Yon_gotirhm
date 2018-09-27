#include <iostream>

using namespace std;

int N;
int MAX;
int countPrint;
int *arr;
int num[15];

void printArr()
{
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] == 1)
        {
            cout << i + 1 << " + ";
        }
        else if (arr[i] == 2)
        {
            cout << i + 1 << " - ";
        }
        else if (arr[i] == 3)
        {
            cout << i + 1 << " . ";
        }
    }
    cout << MAX + 1 << endl;

    return;
}

int treatPoint()
{
    int numCount = 0;

    int a, b, c;
    int flag = 0;

    a = 1;

    for (int i = 0; i < MAX; i++)
    {
        if (flag)
        {
            a = a + i + 1;
        }
        else
        {
            a = i + 1;
        }

        if (arr[i] == 3)
        {
            b = i + 2;
            while (b != 0)
            {
                b = b / 10;
                a = a * 10;
            }
            if (i == MAX - 1)
            {
                num[numCount++] = a + i + 2;
            }
            flag = 1;
        }
        else
        {
            num[numCount++] = a;
            flag = 0;
            if (i == MAX - 1)
            {
                num[numCount++] = i + 2;
            }
        }
    }

    return numCount;
}

int checkSum(int numCount)
{
    int numC = 1;
    int sum = num[0];
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] == 3)
        {
            continue;
        }
        else if (arr[i] == 1)
        {
            sum = sum + num[numC++];
        }
        else if (arr[i] == 2)
        {
            sum = sum - num[numC++];
        }
    }
    if (sum == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void oper(int current, int opr)
{
    arr[current] = opr;
    if (current + 1 == MAX)
    {
        int numCount = treatPoint();
        if (checkSum(numCount))
        {
            if (countPrint < 20)
            {
                printArr();
            }
            countPrint++;
        }

        return;
    }

    oper(current + 1, 1);
    oper(current + 1, 2);
    oper(current + 1, 3);
}

void doRec()
{
    int current = 0;
    oper(current, 1);
    oper(current, 2);
    oper(current, 3);
}

int main(void)
{
    cin >> N;
    MAX = N - 1;
    countPrint = 0;

    arr = new int[N - 1];

    doRec();

    cout << countPrint;
}

/*

Dessert (Dessert.cpp)


문제
농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다. N(1~15)마리의 소들을 순서대로 세 워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. (ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.)

1-2.3-4.5+6.7
이와 같은 배치는 1-23-45+67 을 나타낸다. 결과는 0 이다. 10.11은 1011 로 해석된다.

 

입력
첫 째 줄에는 소들의 수 N이 입력된다.

 

출력
처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다. 마지막 줄에는 가능한 답의 총 가지수를 출력한다.

 

예제 입력
7
예제 출력
1 + 2 - 3 + 4 - 5 - 6 + 7
1 + 2 - 3 - 4 + 5 + 6 - 7
1 - 2 + 3 + 4 - 5 + 6 - 7
1 - 2 - 3 - 4 - 5 + 6 + 7 
1 - 2 . 3 + 4 + 5 + 6 + 7 
1 - 2 . 3 - 4 . 5 + 6 . 7
6
*/