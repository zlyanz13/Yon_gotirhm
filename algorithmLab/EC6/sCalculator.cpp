#include <iostream>
#include <queue>

using namespace std;

int N;

struct Num
{
    int num;
    int count;
};

queue<struct Num *> que;
int visit[100000];

int calcul(struct Num *cur)
{
    int n = cur->num;
    int c = cur->count + 1;

    if (n == N)
    {
        return c - 1;
    }

    if (n > 99999 || n == 0 || visit[n] == 1)
    {
        return -1;
    }
    visit[n] = 1;

    struct Num *tmp;

    tmp = new struct Num;
    tmp->num = n * 2;
    tmp->count = c;
    que.push(tmp);

    tmp = new struct Num;
    tmp->num = n / 3;
    tmp->count = c;
    que.push(tmp);

    return -1;
}
int main(void)
{
    cin >> N;

    struct Num *start = new struct Num;
    start->num = 1;
    start->count = 0;
    fill_n(visit, 100000, 0);
    que.push(start);

    int c = -1;
    while (!que.empty())
    {
        c = calcul(que.front());
        delete (que.front());
        que.pop();
        if (c >= 0)
            break;
    }
    cout << c;
}