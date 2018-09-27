#include <iostream>

using namespace std;

int N, M;
int arr[500];
int brr[501];
int crr[500][501];
int Min = 100000000;

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

    barr(0, N, 1, M, -1);

    cout << Min << endl;
}

/*
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
  0 1 2 3 4  5  6  7  8  9  i 
0 0 0 0 0 0  0  0  0  0  0
1 0 1 4 9 11 13 16 20  
2 0   3 5 7  9  9  11
3 0     5 5  5  7  
4 0       5  5  5 
5 0          5  5
6 0             5
7 0 
8 0 
9 0 

*/