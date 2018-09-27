#include <iostream>

using namespace std;
int N, M;

int *que;

int qhead = 0;
int qRear = 0;

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
            if (qRear == N)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                que[qRear++] = ins;
            }
        }
        else if (ins == 2)
        {
            if (qhead == N || qhead== qRear)
            {
                cout << "Underflow" << endl;
            }
            else
            {
                qhead++;
            }
        }
        else if (ins == 3)
        {
            if (qhead == qRear)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << que[qhead] << endl;
            }
        }
    }
}