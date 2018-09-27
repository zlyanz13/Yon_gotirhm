#include <iostream>

using namespace std;

int N;
int root;
int **link;
int height = 0;

void findHeight(int num, int depth)
{
    if (height < depth)
    {
        height = depth;
    }
    int a = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (link[i][0] == num)
        {
            a = link[i][1];
            link[i][0] = -1;
            link[i][1] = -1;
            findHeight(a, depth + 1);
        }
        else if (link[i][1] == num)
        {
            a = link[i][0];
            link[i][0] = -1;
            link[i][1] = -1;
            findHeight(a, depth + 1);
        }
    }
}

int main(void)
{
    cin >> N >> root;

    link = new int *[N - 1];

    for (int i = 0; i < N - 1; i++)
    {
        link[i] = new int[2];
        cin >> link[i][0] >> link[i][1];
    }

    findHeight(root, 0);
    cout << height;
}