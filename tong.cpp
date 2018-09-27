#include <iostream>
//use BFS
using namespace std;

int N;
char **arr;

int bx[3];
int by[3];
int ex[3];
int ey[3];
int moved = 9999;

void findB();
void findE();

int main(void)
{
    cin >> N;
    arr = new char *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new char[N];
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    findE();
    findB();
    
    cout << moved;
}

void findB()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'B')
            {
                bx[count] = j;
                by[count++] = i;
                if (count == 3)
                {
                    return;
                }
            }
        }
    }
}

void findE()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'B')
            {
                ex[count] = j;
                ey[count++] = i;
                if (count == 3)
                {
                    return;
                }
            }
        }
    }
}