#include <iostream>
#include <queue>
using namespace std;

int N, E;
int start, dest;
int link[100002][2];
int *map;
queue<int *> que;

void queNode(int node)
{
    int *tmp;
    for (int i = 0; i < E; i++)
    {
        if (link[i][0] == node)
        {
            if (map[link[i][1]] != -1)
                continue;
            tmp = new int[2];
            tmp[0] = node;
            tmp[1] = link[i][1];
            que.push(tmp);
        }
        else if (link[i][1] == node)
        {
            if (map[link[i][0]] != -1)
                continue;
            tmp = new int[2];
            tmp[0] = node;
            tmp[1] = link[i][0];
            que.push(tmp);
        }
    }
}

int searchMap(int *p)
{
    int a = p[0];
    int b = p[1];

    if (map[b] == -1)
    {
        map[b] = map[a] + 1;
        if (b == dest)
        {
            return 1;
        }
    }
    else
    {
        if (map[b] > map[a] + 1)
        {
            map[b] = map[a] + 1;
        }
    }

    queNode(b);

    return 0;
}

int main(void)
{
    cin >> N >> E;

    map = new int[N + 1];
    fill_n(map, N + 1, -1);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        link[i][0] = a;
        link[i][1] = b;
    }

    cin >> start >> dest;
    map[start] = 0;

    queNode(start);
    int k = 0;
    while (!que.empty())
    {
        k = searchMap(que.front());
        que.pop();
        if (k)
        {
            cout << map[dest] << endl;
            break;
        }
    }
}
/*
최단거리
 

문제
그래프와 출발점, 도착점이 주어질 때 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 예를 들어, 아래 그림에서 출발 정점이 0, 도착 정점이 10이라고 할 때, 최단거리는 3이다.

alt text

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 1,000,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. M+1 번째 줄에 대하여 출발점과 도착점의 정점 번호가 주어진다.

 

출력
출발점에서 도착점까지 이동하기 위한 최단거리를 출력한다.

 

예제 입력
11 14
0 1
0 2
1 2
1 4
1 5
2 3
3 7
4 7
4 9
4 10
5 6
6 8
6 10
7 8
0 10
예제 출력
3
*/