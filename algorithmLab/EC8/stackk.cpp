#include <iostream>

using namespace std;
int N, M;

int *stk;

int sCount = 0;

int main(void)
{
    cin >> N >> M;

    stk = new int[N];

    int ins;

    for (int i = 0; i < M; i++)
    {
        cin >> ins;
        if (ins == 1)
        {
            cin >> ins;
            if (sCount == N)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                stk[sCount++] = ins;
            }
        }
        else if (ins == 2)
        {
            if (sCount == 0)
            {
                cout << "Underflow" << endl;
            }
            else
            {
                sCount--;
            }
        }
        else if (ins == 3)
        {
            if (sCount == 0)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << stk[sCount - 1] << endl;
            }
        }
    }
}