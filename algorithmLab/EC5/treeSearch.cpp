#include <iostream>

using namespace std;

int **link;

void postOrder(int i)
{
    if (i == -1)
    {
        return;
    }
    postOrder(link[i][1]);
    postOrder(link[i][2]);
    cout << i << " ";
    
}

void inOrder(int i)
{
    if (i == -1)
    {
        return;
    }
    inOrder(link[i][1]);
    cout << i << " ";
    inOrder(link[i][2]);
}

void preOrder(int i)
{
    if (i == -1)
    {
        return;
    }
    cout << i << " ";
    preOrder(link[i][1]);
    preOrder(link[i][2]);
}

int main(void)
{
    int N;
    cin >> N;

    link = new int *[N];

    for (int i = 0; i < N; i++)
    {
        link[i] = new int[3];
        cin >> link[i][0] >> link[i][1] >> link[i][2];
    }

    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
    cout << endl;
}