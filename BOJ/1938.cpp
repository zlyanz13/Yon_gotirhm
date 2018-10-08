#include <iostream>
#include <queue>
//use BFS
using namespace std;

#define HOR 1
#define VER 2
#define U 1
#define D 2
#define L 3
#define R 4
#define T 5

int N;
char arr[51][51];
int map_h[51][51];
int map_v[51][51];

int bx[3];
int by[3];

int moved = 0;

struct point
{
    int dir;
    int inst;
    int x;
    int y;
    int moved;
};

queue<struct point> que;
struct point Epoint;

void findB();
void findE();
void quePoint(int dir, int x, int y, int moved)
{
    struct point tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.dir = dir;
    tmp.moved = moved;

    tmp.inst = U;
    que.push(tmp);
    tmp.inst = D;
    que.push(tmp);
    tmp.inst = L;
    que.push(tmp);
    tmp.inst = R;
    que.push(tmp);
    tmp.inst = T;
    que.push(tmp);
}

int checkTurn(int x, int y)
{
    int xf = x - 1;
    int xl = x + 1;
    int yf = y - 1;
    int yl = y + 1;

    if (xf >= 0 && yf >= 0 && xl < N && yl < N)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[yf + i][xf + j] == '1')
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int movi(struct point current)
{
    int x = current.x;
    int y = current.y;
    int moved = current.moved;

    if (current.dir == HOR)
    {
        switch (current.inst)
        {
        case U:
            if (y - 1 >= 0 && map_h[y - 1][x] != 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (arr[y - 1][x - 1 + i] == '1')
                    {
                        return 0;
                    }
                }
                if (map_h[y - 1][x] == 777)
                {
                    return 1;
                }
                map_h[y - 1][x] = 1;
                quePoint(HOR, x, y - 1, moved + 1);
            }

            break;
        case D:
            if (y + 1 < N && map_h[y + 1][x] != 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (arr[y + 1][x - 1 + i] == '1')
                    {
                        return 0;
                    }
                }
                if (map_h[y + 1][x] == 777)
                {
                    return 1;
                }
                map_h[y + 1][x] = 1;
                quePoint(HOR, x, y + 1, moved + 1);
            }
            break;
        case L:
            if (x - 2 >= 0 && map_h[y][x - 1] != 1)
            {
                if (arr[y][x - 2] == '1')
                {
                    return 0;
                }

                if (map_h[y][x - 1] == 777)
                {
                    return 1;
                }
                map_h[y][x - 1] = 1;
                quePoint(HOR, x - 1, y, moved + 1);
            }
            break;
        case R:
            if (x + 2 < N && map_h[y][x + 1] != 1)
            {
                if (arr[y][x + 2] == '1')
                {
                    return 0;
                }

                if (map_h[y][x + 1] == 777)
                {
                    return 1;
                }
                map_h[y][x + 1] = 1;
                quePoint(HOR, x + 1, y, moved + 1);
            }
            break;
        case T:
            if (checkTurn(x, y) && map_v[y][x] != 1)
            {
                if (map_v[y][x] == 777)
                {
                    return 1;
                }
                map_v[y][x] = 1;

                quePoint(VER, x, y, moved + 1);
            }
            break;
        }
    }
    else if (current.dir == VER)
    {
        switch (current.inst)
        {
        case U:
            if (y - 2 >= 0 && map_v[y - 1][x] != 1)
            {
                if (arr[y - 2][x] == '1')
                {
                    return 0;
                }

                if (map_v[y - 1][x] == 777)
                {
                    return 1;
                }
                map_v[y - 1][x] = 1;
                quePoint(VER, x, y - 1, moved + 1);
            }
            break;
        case D:
            if (y + 2 < N && map_v[y + 1][x] != 1)
            {
                if (arr[y + 2][x] == '1')
                {
                    return 0;
                }

                if (map_v[y + 1][x] == 777)
                {
                    return 1;
                }
                map_v[y + 1][x] = 1;
                quePoint(VER, x, y + 1, moved + 1);
            }
            break;
        case L:
            if (x - 1 >= 0 && map_v[y][x - 1] != 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (arr[y - 1 + i][x - 1] == '1')
                    {
                        return 0;
                    }
                }
                if (map_v[y][x - 1] == 777)
                {
                    return 1;
                }
                map_v[y][x - 1] = 1;
                quePoint(VER, x - 1, y, moved + 1);
            }
            break;
        case R:
            if (x + 1 < N && map_v[y][x + 1] != 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (arr[y - 1 + i][x + 1] == '1')
                    {
                        return 0;
                    }
                }
                if (map_v[y][x + 1] == 777)
                {
                    return 1;
                }
                map_v[y][x + 1] = 1;
                quePoint(VER, x + 1, y, moved + 1);
            }
            break;
        case T:
            if (checkTurn(x, y) && map_h[y][x] != 1)
            {
                if (map_h[y][x] == 777)
                {
                    return 1;
                }
                map_h[y][x] = 1;

                quePoint(HOR, x, y, moved + 1);
            }
            break;
        }
    }

    return 0;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        fill_n(map_h[i], N, 0);
        fill_n(map_v[i], N, 0);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    findB();
    findE();

    while (!que.empty())
    {
        if (movi(que.front()))
        {
            moved = que.front().moved;
            break;
        }
        //cout << "x : " << que.front().x << " y : " << que.front().y << " dir : " << que.front().inst << " H/V : " << que.front().dir << " moved : " << que.front().moved << endl;
        que.pop();
    }

    cout << moved;
}

void findB()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'B')
            {
                if (j + 1 < N && arr[i][j + 1] == 'B')
                {
                    quePoint(HOR, j + 1, i, 1);

                    map_h[i][j + 1] = 1;
                    return;
                }
                else if (i + 1 < N && arr[i + 1][j] == 'B')
                {
                    quePoint(VER, j, i + 1, 1);
                    map_v[i + 1][j] = 1;
                    return;
                }
            }
        }
    }
}

void findE()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'E')
            {
                if (j + 1 < N && arr[i][j + 1] == 'E')
                {
                    map_h[i][j + 1] = 777;
                    return;
                }
                else if (i + 1 < N && arr[i + 1][j] == 'E')
                {
                    map_v[i + 1][j] = 777;
                    return;
                }
            }
        }
    }
}