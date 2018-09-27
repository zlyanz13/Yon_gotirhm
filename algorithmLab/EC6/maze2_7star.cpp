#include <iostream>
#include <queue>

using namespace std;

int column;
int row;
int **pan;
int **copi;

struct cordi
{
    int x;
    int y;
    int moved;
    bool used;
};

queue<struct cordi *> que;

int moveP(struct cordi *current)
{
    int Y = current->y;
    int X = current->x;
    int M = current->moved + 1;
    bool U = current->used;

    struct cordi *tmp;

    if (Y == 0 && X == column - 1)
    {
        return M - 1;
    }
    if (U && pan[Y][X] == 2 || !U && copi[Y][X] == 2)
    {
        return 0;
    }

    if (U)
    {
        pan[Y][X] = 2;
    }
    else
    {
        copi[Y][X] = 2;
    }

    if (X < column - 1)
    {
        if ((U && pan[Y][X + 1] == 0) || (!U && copi[Y][X + 1] == 0))
        {
            tmp = new struct cordi;
            tmp->y = Y;
            tmp->x = X + 1;
            tmp->used = U;
            tmp->moved = M;
            que.push(tmp);
        }
        if (pan[Y][X + 1] == 1 && U)
        {
            tmp = new struct cordi;
            tmp->y = Y;
            tmp->x = X + 1;
            tmp->used = false;
            tmp->moved = M;
            que.push(tmp);
        }
    }
    if (Y < row - 1)
    {
        if ((U && pan[Y + 1][X] == 0) || (!U && copi[Y + 1][X] == 0))
        {
            tmp = new struct cordi;
            tmp->y = Y + 1;
            tmp->x = X;
            tmp->moved = M;
            tmp->used = U;
            que.push(tmp);
        }
        if (pan[Y + 1][X] == 1 && U)
        {
            tmp = new struct cordi;
            tmp->y = Y + 1;
            tmp->x = X;
            tmp->moved = M;
            tmp->used = false;
            que.push(tmp);
        }
    }
    if (Y > 0)
    {
        if ((U && pan[Y - 1][X] == 0) || (!U && copi[Y - 1][X] == 0))
        {
            tmp = new struct cordi;
            tmp->y = Y - 1;
            tmp->x = X;
            tmp->moved = M;
            tmp->used = U;
            que.push(tmp);
        }
        if (pan[Y - 1][X] == 1 && U)
        {
            tmp = new struct cordi;
            tmp->y = Y - 1;
            tmp->x = X;
            tmp->moved = M;
            tmp->used = false;
            que.push(tmp);
        }
    }
    if (X > 0)
    {
        if ((U && pan[Y][X - 1] == 0) || (!U && copi[Y][X - 1] == 0))
        {
            tmp = new struct cordi;
            tmp->y = Y;
            tmp->x = X - 1;
            tmp->moved = M;
            tmp->used = U;
            que.push(tmp);
        }
        if (pan[Y][X - 1] == 1 && U)
        {
            tmp = new struct cordi;
            tmp->y = Y;
            tmp->x = X - 1;
            tmp->moved = M;
            tmp->used = false;
            que.push(tmp);
        }
    }

    return 0;
}

int main(void)
{
    cin >> row >> column;

    pan = new int *[row];
    copi = new int *[row];

    for (int i = 0; i < row; i++)
    {
        pan[i] = new int[column];
        copi[i] = new int[column];

        for (int j = 0; j < column; j++)
        {
            cin >> pan[i][j];
            copi[i][j] = pan[i][j];
        }
    }

    struct cordi *start = new struct cordi;
    start->x = 0;
    start->y = row - 1;
    start->moved = 0;
    start->used = true;

    que.push(start);

    int done = 0;

    while (!que.empty())
    {
        done = moveP(que.front());
        delete que.front();
        que.pop();

        if (done > 0)
            break;
    }

    cout << done;
}