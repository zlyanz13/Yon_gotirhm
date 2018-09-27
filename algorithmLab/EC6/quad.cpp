#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N;
int **pan;

struct tile
{
    int x;
    int y;
    int len;
};

stack<int> bin;
stack<char> hexa;

queue<struct tile *> que;

void check(struct tile *block)
{
    int len = block->len;
    int x = block->x;
    int y = block->y;
    int half = len / 2;
    int check = pan[y][x];
    int flag = 0;

    for (int i = y; i < y + len; i++)
    {
        for (int j = x; j < x + len; j++)
        {
            if (check != pan[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }

    if (!flag)
    {
        bin.push(0);
        bin.push(check);
    }
    else
    {
        bin.push(1);

        if (half > 0)
        {
            struct tile *tmp;

            tmp = new struct tile;
            tmp->len = half;
            tmp->x = x;
            tmp->y = y;
            que.push(tmp);

            tmp = new struct tile;
            tmp->len = half;
            tmp->x = x + half;
            tmp->y = y;
            que.push(tmp);

            tmp = new struct tile;
            tmp->len = half;
            tmp->x = x;
            tmp->y = y + half;
            que.push(tmp);

            tmp = new struct tile;
            tmp->len = half;
            tmp->x = x + half;
            tmp->y = y + half;
            que.push(tmp);
        }
    }
}

int main(void)
{
    cin >> N;
    pan = new int *[N];

    for (int i = 0; i < N; i++)
    {
        pan[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> pan[i][j];
        }
    }
    struct tile *start = new struct tile;
    start->len = N;
    start->x = 0;
    start->y = 0;

    que.push(start);
    while (!que.empty())
    {
        check(que.front());
        que.pop();
    }

    int a = 0;
    int top;
    int count = 0;
    while (!bin.empty())
    {
        top = bin.top();
        bin.pop();

        for (int i = 0; i < count; i++)
        {
            top *= 2;
        }

        a = a + top;
        count++;

        if (count == 4)
        {
            if (a < 10)
            {
                hexa.push('0' + a);
            }
            else if (a >= 10)
            {
                hexa.push('A' + a - 10);
            }

            count = 0;
            a = 0;
        }
    }
    if (count > 0)
    {
        if (a < 10)
        {
            hexa.push('0' + a);
        }
        else if (a >= 10)
        {
            hexa.push('A' + a - 10);
        }
    }

    while (!hexa.empty())
    {
        cout << hexa.top();
        hexa.pop();
    }
}