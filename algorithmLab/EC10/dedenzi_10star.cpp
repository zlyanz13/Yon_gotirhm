#include <iostream>

using namespace std;

int N, M;
int arr[500];
int brr[501];
int crr[500][501];
int Min = 100000000;

int drr[501][501];
int qqq[100000];

//barr(0, N, 1, M, -1);
void barr(int start, int total, int startB, int totalB, int Max)
{
    if (Max >= Min)
    {
        return;
    }

    if (startB == totalB)
    {
        brr[startB] = N - 1;
        Max = (Max < crr[brr[startB]][brr[startB] - brr[startB - 1]])
                  ? crr[brr[startB]][brr[startB] - brr[startB - 1]]
                  : Max;

        if (Max < Min)
        {
            Min = Max;
        }
        return;
    }

    for (int i = start; i < total - (totalB - (startB - 1) - 1); i++)
    {
        brr[startB] = i;

        Max = (Max < crr[brr[startB]][brr[startB] - brr[startB - 1]])
                  ? crr[brr[startB]][brr[startB] - brr[startB - 1]]
                  : Max;

        barr(i + 1, total, startB + 1, totalB, Max);
    }
}

void checkMax()
{
    int tmax = -1;
    for (int i = 0; i < M; i++)
    {
        if (tmax < crr[qqq[i + 1]][qqq[i + 1] - qqq[i]])
        {
            tmax = crr[qqq[i + 1]][qqq[i + 1] - qqq[i]];
        }
    }
    if (tmax < Min)
    {
        Min = tmax;
    }
}

void getReady(int bef, int s, int ee)
{
    if (s > ee)
    {
        checkMax();
        return;
    }
    for (int i = bef; i < N - 1 - (ee - s); i++)
    {
        qqq[s] = i;
        getReady(i + 1, s + 1, ee);
    }
}

void carr()
{
    qqq[0] = -1;
    qqq[M] = N - 1;
    // 1 ~ N-2 까지
    getReady(0, 1, M - 1);
}

void darr()
{
    int hap = 0;
    for (int i = 1; i < N + 1; i++)
    {
        hap += arr[i - 1];
        drr[i][1] = hap;
    }
    for (int i = 2; i < N + 1; i++)
    {
        drr[i][i] = max(drr[i - 1][i - 1], arr[i - 1]);
    }

    for (int i = 2; i < M + 1; i++)
    {
        for (int j = i + 1; j < N + 1; j++)
        {
            drr[j][i] = max(drr[j - 1][i - 1], arr[j - 1]);
            for (int k = j - 2; k >= i - 1; k--)
            {
                drr[j][i] = min(drr[j][i], max(drr[k][i - 1], drr[j][1] - drr[k][1]));
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    // 팀을 나눈 후 팀별 점수의 최댓값이 최소가 되야함
    // 칸막이는 N-2 까지만, N-1 까지 올수없음
    // 즉 N명 칸막이 M개일때 ((N-1)C(M-1)))
    // 최대
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    /*
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < i + 1; j++)
        {
            sum += arr[i - j];
            crr[i][j + 1] = sum;
        }
    }
     brr[0] = -1;
    */
    //barr(0, N, 1, M, -1);
    //carr();
    darr();

    cout << drr[N][M] << endl;
}
/*
10?3 = 

10 3
1 3 5 2 2 3 4 6 3 1

arr[0] =  1 + 3 + 5 + 2 + 2 + 3 + 4 + 6 + 3 + 1 = 30 

arr[1] =  1 + 3 + 5 + 2 + 2 + 3 / 4 + 6 + 3 + 1 = 16

arr[2] =  1 + 3 + 5 / 2 + 2 + 3 + 4 / 6 + 3 + 1 = 11

arr[3] =  1 + 3 + 5 / 2 + 2 + 3 / 4 + 6 / 3 + 1 = 10

arr[4] =  1 + 3 + 5 / 2 + 2 + 3 / 4 / 6 / 3 + 1 = 9

arr[5] =  1 + 3 / 5 + 2 / 2 + 3 / 4 / 6 / 3 + 1 = 7

arr[6] =  1 + 3 / 5 / 2 / 2 + 3 / 4 / 6 / 3 + 1 = 6

arr[7] =  1 + 3 / 5 / 2 / 2 + 3 / 4 / 6 / 3 / 1 = 6

arr[8] =  1 + 3 / 5 / 2 / 2 / 3 / 4 / 6 / 3 / 1 = 6

arr[9] =  1 + 3 + 5 + 2 + 2 + 3 + 4 + 6 + 3 + 1 = 6 

i명의 학생으로 j개 팀을 만들때에 최대의 최소
   j     1  3  5  2  2  3  4  6  3  1
i
      0  1  2  3  4  5  6  7  8  9  10 
   0  /  
1  1     1  4  9  11 13 16 20 26 29 30
3  2     4  3  
5  3     9  5  5   
2  4     11 7     5        
2  5     13 9       5  
2  6     16             5 
3  7     20                6  
4  8     26                   6  
6  9     29                      6  
3  10    30                         6


팀 나누기
 

문제
N명의 학생을 M개의 팀으로 나누려고 한다. 각 학생은 본인의 능력을 나타내는 숫자를 하나씩 갖고 있으며, 편의상 팀을 나눌 때에는 연속한 학생들을 하나의 팀으로 만든다고 하자. 예를 들어, 다음 그림은 10명의 학생을 3개의 팀으로 나누는 두 가지 예이다.

alt text

각 팀의 점수는 그 팀에 속한 학생들의 점수의 합이다. 예를 들어, 첫 번째의 경우 각 팀의 점수는 9/7/14 가 되며, 두 번째의 경우에는 4/16/10 이 된다. 팀을 잘 나누기 위해서는, 각 팀의 점수가 비슷해야 한다. 즉, 하나의 팀의 점수가 매우 높아서는 안 된다. 따라서 점수가 최대인 팀의 점수를 최대한 적게 만들고 싶다. 위의 예제에서는 아래와 같이 나누게 되면, 각 팀의 점수가 9/11/10 이 된다. 점수가 최대인 팀은 11이며, 어떻게 하더라도 점수가 가장 높은 팀을 11보다 적게 팀을 나눌 수는 없다.

alt text

N명의 학생의 점수와 나누고자 하는 팀의 개수 M이 주어질 때, 점수가 가장 높은 팀이 갖는 점수의 최솟값을 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 학생의 수 N과 나누고자 하는 팀의 개수 M이 주어진다. (1 ≤ N, M ≤ 500) 두 번째 줄에는 N명의 학생의 점수가 주어진다.  

출력
점수가 가장 높은 팀이 갖는 점수의 최솟값을 출력한다.

 

예제 입력
10 3
1 3 5 2 2 3 4 6 3 1
예제 출력
11
*/