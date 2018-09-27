#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void)
{
    string x, y;

    cin >> n;

    vector<string> vec;

    for (int i = 0; i < n; i++)
    {
        string arr;
        cin >> arr;
        vec.push_back(arr);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << endl;
    }
}