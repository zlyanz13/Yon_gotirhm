#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string x;
    getline(cin, x);

    string y = "";

    for (int i = 0; i < x.length(); i++)
    {
        y += x[x.length() - i - 1];
    }
    if (x == y)
        cout << "YES";

    else
    {
        cout << "NO";
    }
}