#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string x, y;

    cin >> x >> y;

    if (x.find(y) != -1)
        cout << "YES";
    else
        cout << "NO";
}