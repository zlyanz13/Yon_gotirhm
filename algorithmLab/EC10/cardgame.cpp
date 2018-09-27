#include <iostream>

using namespace std;

int N;
int arr[100001];
int brr[100001];


int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    brr[0] = 0;
    brr[1] = arr[1];
    brr[2] = arr[1] + arr[2];

    if (arr[3] <= arr[1] && arr[3] <= arr[2])
    {
        brr[3] = arr[1] + arr[2];
    }
    else if (arr[1] <= arr[3] && arr[1] <= arr[2])
    {
        brr[3] = arr[2] + arr[3];
    }
    else if (arr[2] <= arr[3] && arr[2] <= arr[1])
    {
        brr[3] = arr[1] + arr[3];
    }

    for (int i = 4; i <= N; i++)
    {
        int a = brr[i - 3] + arr[i - 1] + arr[i];
        int b = brr[i - 2] + arr[i];
        int c = brr[i - 4] + arr[i - 2] + arr[i - 1];

        int MAX;
        if (a >= b && a >= c)
        {
            MAX = a;
        }
        else if (b >= a && b >= c)
        {
            MAX = b;
        }
        else if (c >= a && c >= b)
        {
            MAX = c;
        }
        brr[i] = MAX;
    }

    cout << brr[N];
}

/*

3 : 1, 2(1>3) / 2, 3(1<3)/ 1,3

4 : 1, 2, 4 /1, 3, 4 / 2, 3 (2 + 3)
3o4o / 3x4o / 3o4x 

5 : 1, 2, 4, 5 / 2, 4,5 / 1, 3, 4 (3 + 4)
[2]4o5o / [3]4x5o / [1]3o4o5x

6 : 1,2,4,5/2,3,5,6/1,3,4,6
[3]4x5o6o / [4]5x6o / [2]4o5o6x

7 : [4]6o7o / [5]6x7o / [3]5o6o7x
*/
/*
카드 놀이
 

문제
N개의 카드가 주어지고, 각각은 자연수의 점수를 가진다. 철수는 이제 이 카드를 가져감으로써 카드에 적혀있는 수 만큼의 점수를 얻는다. 단, 카드를 가져갈 때 한가지 규칙이 있는데, 이는 연속하여 3개의 카드는 가져갈 수 없다는 것이다. 예를 들어, 6개의 카드 “1 3 5 2 7 3”가 주어질 경우, 3+5+7+3 = 18 만큼의 점수를 얻는 것이 최대이다. N개의 카드가 주어질 때, 얻을 수 있는 점수의 최댓값을 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 두 번째 줄에 N개의 숫자가 주어지며, 이는 각 카드의 점수를 나타낸다.  

출력
얻을 수 있는 점수의 최댓값을 출력한다.

 

예제 입력
6
1 3 5 2 7 3
예제 출력
18
*/