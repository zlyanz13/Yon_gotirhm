#include <iostream>
#include <queue>

using namespace std;

int N;
int edge;
int *map;
int *visit;
int **link;

queue<int> que;

int chill(int n)
{
    if (visit[n-1] != 0)
    {
        return 1;
    }
    visit[n-1] = 1;

    for (int i = 0; i < edge; i++)
    {
        if (link[i][0] == n)
        {
            if (map[link[i][1]-1] == 0)
            {
                que.push(link[i][1]);
                map[link[i][1]-1] = map[n-1] % 2 + 1;
            }
            else
            {
                if (map[n-1] == map[link[i][1]-1])
                    return 0;
            }
        }
        else if (link[i][1] == n)
        {
            if (map[link[i][0]-1] == 0)
            {
                que.push(link[i][0]);
                map[link[i][0]-1] = map[n-1] % 2 + 1;
            }
            else
            {
                if (map[n-1] == map[link[i][0]-1])
                    return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    cin >> N >> edge;
    map = new int[N];
    fill_n(map, N, 0);

    visit = new int[N];
    fill_n(visit, N, 0);
    link = new int *[edge];

    for (int i = 0; i < edge; i++)
    {
        link[i] = new int[2];
        cin >> link[i][0] >> link[i][1];
    }

    int yes = 1;
    que.push(link[0][0]);
    map[link[0][0]-1] = 1;
    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        yes = chill(a);
        if (yes == 0)
            break;
    }

    if (yes)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}