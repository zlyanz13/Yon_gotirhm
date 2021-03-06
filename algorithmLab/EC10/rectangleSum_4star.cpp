#include <stdio.h>

int N, M, Q;
int arr[1001][1001];
int brr[1001][1001];

int x1, y1, x2, y2;

int main(void)
{
    scanf("%d %d %d", &N, &M, &Q);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        sum = arr[i][0] + sum;
        brr[i][0] = sum;
    }
    sum = 0;
    for (int j = 0; j < M; j++)
    {
        sum += arr[0][j];
        brr[0][j] = sum;
    }
    for (int i = 1; i < N; i++)
    {
        sum = arr[i][0];
        for (int j = 1; j < M; j++)
        {
            sum += arr[i][j];
            brr[i][j] = sum + brr[i - 1][j];
        }
    }

    int tmp;
    for (int k = 0; k < Q; k++)
    {
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        if (x1 == 0 && y1 != 0)
        {
            sum = brr[y2][x2] - brr[y1 - 1][x2];
        }
        else if (x1 != 0 && y1 == 0)
        {
            sum = brr[y2][x2] - brr[y2][x1 - 1];
        }
        else if (y1 == 0 && x1 == 0)
        {
            sum = brr[y2][x2];
        }
        else
        {
            sum = brr[y2][x2] - brr[y2][x1 - 1] - brr[y1 - 1][x2] + brr[y1 - 1][x1 - 1];
        }

        printf("%d\n", sum);
    }
}
/*
cin, cout의 속도로 인해 오류발생

직사각형의 합
 

문제
N(Row) x M(Col) 의 직사각형이 주어지며, 각 칸에는 정수가 들어있다. 이제 Q개의 질문에 대하여 답을 해야 하며, 각각의 질문은 (a, b)부터 (c, d)까지의 직사각형에 들어있는 정수의 합을 묻는다. 예를 들어, 다음과 같이 5 x 5 의 직사각형이 주어질 때, (1, 2) 부터 (3, 3) 까지의 직사각형에 들어있는 정수의 합은 26 이다.

alt text

 

입력
첫 번째 줄에 N, M, Q가 주어진다. ( 1 ≤ N, M ≤ 1,000, 1 ≤ Q ≤ 1,000,000 ) 두 번째 줄부터 N x M 직사각형에 주어진다. 그 후 Q개의 질문이 주어진다. 각각의 질문은 “a b c d” 로 이루어 져 있으며, 이는 (a, b) 부터 (c, d) 까지의 직사각형에 들어있는 정수의 합을 묻는다.  

출력
각 질문에 대한 답을 출력한다.

 

예제 입력
5 5 3
 1 -2 3 2 8
-8 -9 3 4 5
 2 4 7 8 2
 1 4 3 1 4
-1 2 5 -6 3
1 2 3 4
0 0 1 1
2 0 2 1
예제 출력
37
-18
6
*/