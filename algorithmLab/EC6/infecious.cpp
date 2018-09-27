#include <iostream>
#include <queue>

using namespace std;

int N;
int count;
queue<int> que;
int visit[100001];

void calcul(int n)
{
    if (n > N || n == 0 || visit[n] == 1)
    {
        return;
    }

    visit[n] = 1;
    count--;

    que.push(n * 2);

    que.push(n / 3);

    return;
}
int main(void)
{
    cin >> N;
    int startN;
    cin >> startN;

    fill_n(visit, 100001, 0);

    que.push(startN);

    count = N;

    while (!que.empty())
    {
        calcul(que.front());
        que.pop();
    }
    cout << count;
}