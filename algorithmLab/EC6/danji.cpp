#include <iostream>

using namespace std;
int count;

string *input;
int arr[26] = {0};

void sort(int count)
{
    int min;
    int minindex;
    int tmp;
    for (int i = 0; i < count - 1; i++)
    {
        min = arr[i];
        minindex = i;
        for (int j = i; j < count; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minindex = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = tmp;
    }
}

void rec(int x, int y, int max)
{
    input[x][y] = 'a' + count;
    arr[count]++;

    if (x > 0 && input[x - 1][y] == '1')
    {
        rec(x - 1, y, max);
    }

    if (y > 0 && input[x][y - 1] == '1')
    {
        rec(x, y - 1, max);
    }

    if (x + 1 < max && input[x + 1][y] == '1')
    {
        rec(x + 1, y, max);
    }
    if (y + 1 < max && input[x][y + 1] == '1')
    {
        rec(x, y + 1, max);
    }
}

int main(void)
{
    int n;
    count = 0;
    cin >> n;

    input = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (input[i][j] == '1')
            {
                rec(i, j, n);
                count++;
            }
        }
    }

    cout << count << endl;
    sort(count);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }
}