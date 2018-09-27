#include <iostream>

using namespace std;

int *map;
int **arr;
int count;

void defect(int n, int link)
{
    map[n - 1] = -1;
    count++;

    for (int i = 0; i < link; i++)
    {
        if (arr[i][0] == -1)
        {
            continue;
        }

        if (arr[i][0] == n)
        {
            if (map[arr[i][1] - 1] == 1)
            {
                defect(arr[i][1], link);
                arr[i][0] = -1;
                arr[i][1] = -1;
            }
        }
        else if (arr[i][1] == n)
        {
            if (map[arr[i][0] - 1] == 1)
            {
                defect(arr[i][0], link);
                arr[i][0] = -1;
                arr[i][1] = -1;
            }
        }
    }
}

int main(void)
{

    int n;
    int link;

    cin >> n >> link;

    map = new int[n];
    arr = new int *[link];

    for (int i = 0; i < n; i++)
    {
        map[i] = 1;
    }
    for (int i = 0; i < link; i++)
    {
        arr[i] = new int[2];
        cin >> arr[i][0] >> arr[i][1];
    }

    count = 0;
    defect(1, link);

    cout << count - 1;
}