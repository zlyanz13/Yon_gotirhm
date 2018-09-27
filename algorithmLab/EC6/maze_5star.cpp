#include <iostream>
#include <queue>

using namespace std;

int column;
int row;
int **pan;

struct cordi
{
    int x;
    int y;
    int moved;
};

queue<struct cordi *> que;

int moveP(struct cordi *current)
{
    int Y = current->y;
    int X = current->x;
    int M = current->moved + 1;

    struct cordi *tmp;

    if (Y == 0 && X == column - 1)
    {
        return M - 1;
    }
    if (pan[Y][X] == 2)
    {
        return 0;
    }

    pan[Y][X] = 2;

    if (X < column - 1 && pan[Y][X + 1] == 0)
    {
        tmp = new struct cordi;
        tmp->y = Y;
        tmp->x = X + 1;
        tmp->moved = M;
        que.push(tmp);
    }
    if (Y < row - 1 && pan[Y + 1][X] == 0)
    {
        tmp = new struct cordi;
        tmp->y = Y + 1;
        tmp->x = X;
        tmp->moved = M;
        que.push(tmp);
    }
    if (Y > 0 && pan[Y - 1][X] == 0)
    {
        tmp = new struct cordi;
        tmp->y = Y - 1;
        tmp->x = X;
        tmp->moved = M;
        que.push(tmp);
    }
    if (X > 0 && pan[Y][X - 1] == 0)
    {
        tmp = new struct cordi;
        tmp->y = Y;
        tmp->x = X - 1;
        tmp->moved = M;
        que.push(tmp);
    }

    return 0;
}

int main(void)
{
    cin >> row >> column;

    pan = new int *[row];
    for (int i = 0; i < row; i++)
    {
        pan[i] = new int[column];
        for (int j = 0; j < column; j++)
        {
            cin >> pan[i][j];
        }
    }

    struct cordi *start = new struct cordi;
    start->x = 0;
    start->y = row - 1;
    start->moved = 0;

    que.push(start);

    int done = 0;
    while (!que.empty())
    {
        done = moveP(que.front());
        delete (que.front());
        que.pop();

        if (done > 0)
            break;
    }
    cout << done;
}