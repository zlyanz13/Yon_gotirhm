#include <iostream>

using namespace std;

char harr[80] = {'1'};

char mini[80] = {0};

int done = 0;

void checkMin(int max)
{
    int flag = 0;
    for (int i = 0; i < max; i++)
    {
        if (harr[i] == mini[i])
        {
            continue;
        }
        else if (harr[i] < mini[i])
        {
            flag = 1;
            break;
        }
        else
        {
            return;
        }
    }
    if (flag)
    {
        for (int i = 0; i < max; i++)
        {
            mini[i] = harr[i];
        }
    }
}

int inspect(int n)
{
    int count;
    int max = n / 2 + 1;

    for (int i = 2; i < max; i++)
    {
        int max2 = n - 2 * i + 1;

        for (int j = 0; j < max2; j++)
        {
            count = 1;
            for (int k = j; k < j + i; k++)
            {
                if (harr[k] != harr[k + i])
                {
                    count = 0;
                    break;
                }
            }
            if (count)
            {
                return 0;
            }
        }
    }
    return 1;
}

void doRec(int count, int n, int max)
{
    harr[count] = '0' + n;

    if (count + 1 == max)
    {

        if (inspect(max))
        {
            checkMin(max);
            done = 0;
        }

        return;
    }

    if (done)
    {
        return;
    }

    if (!inspect(count + 1))
    {
        return;
    }

    for (int i = 1; i < count + 1; i++)
    {
        if (harr[i] == mini[i])
        {
            continue;
        }
        else if (harr[i] < mini[i])
        {
            break;
        }
        else
        {
            return;
        }
    }
    if (n != 1)
    {
        doRec(count + 1, 1, max);
    }
    if (n != 2)
    {
        doRec(count + 1, 2, max);
    }
    if (n != 3)
    {
        doRec(count + 1, 3, max);
    }
}

int main(void)
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        mini[i] = '9';
        harr[i] = '0';
    }

    doRec(0, 1, n);

    cout << mini << endl;
}

/*
좋은 수열 (goodseq.cpp)
 

문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.

33

32121323

123123213

다음은 좋은 수열의 예이다.

2

32

32123

1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다.

 

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

 

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내 는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.

 

예제 입력
7
예제 출력
1213121
*/