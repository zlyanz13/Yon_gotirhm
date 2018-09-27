#include <iostream>

using namespace std;

char **link;
int *map;
char *stack;
int currentStack;

char *queue;
int currentque;
int quehead;

int edge;

// Sort에서 for문 변수를 잘못썼다,,,,
char popQue()
{
    return queue[quehead++];
}

void sortQue(int start, int end)
{
    int minNum;
    char minChar;
    for (int i = start; i < end - 1; i++)
    {
        minChar = queue[i];
        minNum = i;
        for (int j = i + 1; j < end; j++)
        {
            if (queue[j] < minChar)
            {
                minNum = j;
                minChar = queue[j];
            }
        }

        char tmp = queue[i];
        queue[i] = minChar;
        queue[minNum] = tmp;
    }
}

void bfs(char a)
{
    if (map[a - 'A'] != 1)
    {
        return;
    }
    cout << a;
    map[a - 'A'] = -1;

    int qCount = 0;

    for (int i = 0; i < edge; i++)
    {
        if (link[i][0] == a)
        {
            if (map[link[i][1] - 'A'] == 1)
            {
                queue[currentque++] = link[i][1];
                qCount++;
            }
        }
        else if (link[i][1] == a)
        {
            if (map[link[i][0] - 'A'] == 1)
            {
                queue[currentque++] = link[i][0];
                qCount++;
            }
        }
    }

    sortQue(currentque - qCount, currentque);
}

void sortStack(int sCount)
{
    int max;
    char maxC;

    for (int i = 0; i < sCount - 1; i++)
    {
        maxC = stack[currentStack - 1 - i];
        max = currentStack - 1 - i;

        for (int j = i + 1; j < sCount; j++)
        {
            if (maxC > stack[currentStack - 1 - j])
            {
                maxC = stack[currentStack - 1 - j];
                max = currentStack - 1 - j;
            }
            char tmp = stack[currentStack - 1 - i];
            stack[currentStack - 1 - i] = maxC;
            stack[max] = tmp;
        }
    }
}

char popStack()
{
    currentStack = currentStack - 1;
    return stack[currentStack];
}

void dfs(char a)
{
    if (map[a - 'A'] == -1)
    {
        return;
    }
    cout << a;
    map[a - 'A'] = -1;

    int sCount = 0;

    for (int i = 0; i < edge; i++)
    {

        if (link[i][0] == a)
        {
            if (map[link[i][1] - 'A'] == 1)
            {
                stack[currentStack++] = link[i][1];
                sCount++;
            }
        }
        else if (link[i][1] == a)
        {
            if (map[link[i][0] - 'A'] == 1)
            {
                stack[currentStack++] = link[i][0];
                sCount++;
            }
        }
    }

    sortStack(sCount);
}

int main(void)
{
    int n, e;

    cin >> n >> e;
    edge = e;

    map = new int[n];
    stack = new char[400];
    queue = new char[1000];

    fill_n(map, n, 1);

    link = new char *[e];

    for (int i = 0; i < e; i++)
    {
        link[i] = new char[2];
        cin >> link[i][0] >> link[i][1];
    }

    char start;

    cin >> start;

    currentStack = 1;
    stack[0] = start;

    while (currentStack != 0)
    {
        dfs(popStack());
    }

    cout << endl;

    fill_n(map, n, 1);

    queue[0] = start;
    currentque = 1;
    quehead = 0;

    while (currentque != quehead)
    {
        bfs(popQue());
    }
    cout << endl;
}