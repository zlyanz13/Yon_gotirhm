#include <iostream>

using namespace std;
int N, M;

int *que;

int qhead = 0;
int qCount = 0;

int main(void)
{
    cin >> N >> M;

    que = new int[N];

    int ins;

    for (int i = 0; i < M; i++)
    {
        cin >> ins;
        if (ins == 1)
        {
            cin >> ins;
            if (qCount == N)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                que[(qhead + qCount) % N] = ins;
                qCount++;
            }
        }
        else if (ins == 2)
        {
            if (qCount == 0)
            {
                cout << "Underflow" << endl;
            }
            else
            {
                qhead++;
                qCount--;
            }
        }
        else if (ins == 3)
        {
            if (qCount == 0)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << que[qhead % N] << endl;
            }
        }
    }
}