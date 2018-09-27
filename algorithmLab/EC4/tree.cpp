#include <iostream>

using namespace std;

char arr[26][3];

void postO(int max, char a)
{
    if (a == '.')
    {
        return;
    }

    int i;
    for (i = 0; i < max; i++)
    {
        if (arr[i][0] == a)
            break;
    }
    postO(max, arr[i][1]);
    postO(max, arr[i][2]);
    cout << arr[i][0];
}

void inO(int max, char a)
{
    if (a == '.'){
        return;
    }

    int i;
    for (i = 0; i < max; i++)
    {
        if (arr[i][0] == a)
            break;
    }
    inO(max, arr[i][1]);
    cout << arr[i][0];
    
    inO(max, arr[i][2]);
}

void preO( int max, char a)
{
    if(a=='.') return;
    int i;
    for( i=0;i<max;i++){
        if(arr[i][0]==a) break;
    }
    cout << arr[i][0];
    preO(max,arr[i][1]);
    preO( max, arr[i][2]);
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    preO(n, 'A');
    cout<<endl;
    inO(n,'A');
    cout<<endl;
    postO(n,'A');
}