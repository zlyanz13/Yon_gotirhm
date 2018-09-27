#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N;
int edge;
int **link;
int *map;

queue<int> Qbfs;
queue<int> tmpQ;
stack<int> Sdfs;

void queSort(int qCount)
{
    int *newArr = new int[qCount];
    for (int i = 0; i < qCount; i++)
    {
        newArr[i] = tmpQ.front();
        tmpQ.pop();
    }

    for (int i = 0; i < qCount - 1; i++)
    {
        int min = newArr[i];
        int minIndex = i;

        for (int j = i + 1; j < qCount; j++)
        {
            if (min > newArr[j])
            {
                min = newArr[j];
                minIndex = j;
            }
        }

        int tmp = newArr[i];
        newArr[i] = min;
        newArr[minIndex] = tmp;
    }

    for (int i = 0; i < qCount; i++)
    {
        Qbfs.push(newArr[i]);
    }
    delete(newArr);
}

void bfs(int n)
{
    
    if (map[n] != 1)
    {
        return;
    }
    cout << n << " ";
    map[n] = -1;

    int qCount = 0;
    for (int i = 0; i < edge; i++)
    {
        if (link[i][0] == n)
        {
            if (map[link[i][1]] == 1)
            {
                tmpQ.push(link[i][1]);

                qCount++;
                continue;
            }
        }
        else if (link[i][1] == n)
        {
            if (map[link[i][0]] == 1)
            {
                tmpQ.push(link[i][0]);
                qCount++;
                continue;
            }
        }
    }

    queSort(qCount);
}

void sortStack(int sCount)
{
    int *newStack = new int[sCount];

    for (int i = 0; i < sCount; i++)
    {
        newStack[i] = Sdfs.top();
        Sdfs.pop();
    }

    for (int i = 0; i < sCount - 1; i++)
    {
        int min = newStack[i];
        int minIndex = i;

        for (int j = i + 1; j < sCount; j++)
        {
            if (min < newStack[j])
            {
                min = newStack[j];
                minIndex = j;
            }
        }

        int tmp = newStack[i];
        newStack[i] = min;
        newStack[minIndex] = tmp;
    }
    for (int i = 0; i < sCount; i++)
    {
        Sdfs.push(newStack[i]);
    }
}

void dfs(int n)
{
    if (map[n] != 1)
    {
        return;
    }
    cout << n << " ";
    map[n] = -1;

    int sCount = 0;

    for (int i = 0; i < edge; i++)
    {
        if (link[i][0] == n)
        {
            if (map[link[i][1]] == 1)
            {
                Sdfs.push(link[i][1]);
                sCount++;
                continue;
            }
        }
        else if (link[i][1] == n)
        {
            if (map[link[i][0]] == 1)
            {
                Sdfs.push(link[i][0]);
                sCount++;
                continue;
            }
        }
    }

    sortStack(sCount);
}

int main()
{
    cin >> N >> edge;
    link = new int *[edge];
    map = new int[N];

    for (int i = 0; i < edge; i++)
    {
        link[i] = new int[2];
        cin >> link[i][0] >> link[i][1];
    }

    fill_n(map, N, 1);

    Sdfs.push(0);
    while (!Sdfs.empty())
    {
        int a = Sdfs.top();
        Sdfs.pop();
        dfs(a);
    }
    cout << endl;

    fill_n(map, N, 1);

    Qbfs.push(0);
    while (!Qbfs.empty())
    {
        bfs(Qbfs.front());
        Qbfs.pop();
    }
    cout << endl;
}